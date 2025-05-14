const express = require('express');
const axios = require('axios');
const router = express.Router();

// Exchange authorization code for access token
router.post('/token', async (req, res) => {
  const { code } = req.body;

  try {
    const response = await axios.post('https://www.strava.com/oauth/token', {
      client_id: process.env.STRAVA_CLIENT_ID,
      client_secret: process.env.STRAVA_CLIENT_SECRET,
      code,
      grant_type: 'authorization_code',
    });

    res.json(response.data);
  } catch (err) {
    console.error(err.response.data);
    res.status(500).json({ error: 'Failed to get Strava token' });
  }
});

// Get activity data
router.get('/activities', async (req, res) => {
  const { access_token } = req.query;

  try {
    const response = await axios.get('https://www.strava.com/api/v3/athlete/activities', {
      headers: { Authorization: `Bearer ${access_token}` }
    });

    res.json(response.data);
  } catch (err) {
    console.error(err.response.data);
    res.status(500).json({ error: 'Failed to fetch activities' });
  }
});

module.exports = router;
