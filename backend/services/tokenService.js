const axios = require('axios');
const Token = require('../models/Token');

async function getValidAccessToken(athleteId) {
  const tokenData = await Token.findOne({ athleteId });
  if (!tokenData) throw new Error('No token found for user');

  const now = Math.floor(Date.now() / 1000); // current UNIX timestamp in seconds

  // If token is still valid, return it
  if (tokenData.expiresAt > now) {
    return tokenData.accessToken;
  }

  // Otherwise, refresh it
  const refreshRes = await axios.post('https://www.strava.com/oauth/token', {
    client_id: process.env.STRAVA_CLIENT_ID,
    client_secret: process.env.STRAVA_CLIENT_SECRET,
    grant_type: 'refresh_token',
    refresh_token: tokenData.refreshToken
  });

  const { access_token, refresh_token, expires_at } = refreshRes.data;

  // Update in DB
  tokenData.accessToken = access_token;
  tokenData.refreshToken = refresh_token;
  tokenData.expiresAt = expires_at;
  await tokenData.save();

  return access_token;
}

module.exports = { getValidAccessToken };
