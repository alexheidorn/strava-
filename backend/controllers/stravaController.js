const axios = require('axios');
const Token = require('../models/Token');


exports.redirectToStrava = (req, res) => {
  const url = `https://www.strava.com/oauth/authorize?client_id=${process.env.STRAVA_CLIENT_ID}&response_type=code&redirect_uri=${process.env.STRAVA_REDIRECT_URI}&approval_prompt=auto&scope=activity:read`;
  res.redirect(url);
};

exports.handleOAuthCallback = async (req, res) => {
  const { code } = req.query;

  try {
    const tokenRes = await axios.post(`https://www.strava.com/oauth/token`, {
      client_id: process.env.STRAVA_CLIENT_ID,
      client_secret: process.env.STRAVA_CLIENT_SECRET,
      code,
      grant_type: 'authorization_code'
    });

    const { access_token, refresh_token, expires_at, athlete } = tokenRes.data;

    // Save or update token
    await Token.findOneAndUpdate(
      { athleteId: athlete.id },
      {
        accessToken: access_token,
        refreshToken: refresh_token,
        expiresAt: expires_at
      },
      { upsert: true, new: true }
    );

    res.json({ message: 'Token stored', athleteId: athlete.id });
  } catch (err) {
    console.error(err);
    res.status(500).json({ error: 'Token exchange failed' });
  }
};

exports.getActivities = async (req, res) => {
  const { token } = req.query;

  try {
    const actRes = await axios.get(`https://www.strava.com/api/v3/athlete/activities`, {
      headers: { Authorization: `Bearer ${token}` }
    });

    res.json(actRes.data);
  } catch (err) {
    res.status(500).json({ error: 'Failed to fetch activities' });
  }
};
