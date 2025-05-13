const express = require("express");
const axios = require("axios");
const router = express.Router();

const CLIENT_ID = process.env.STRAVA_CLIENT_ID;
const CLIENT_SECRET = process.env.STRAVA_CLIENT_SECRET;
const REDIRECT_URI = process.env.STRAVA_REDIRECT_URI;

// Exchange code for access token
router.post("/auth", async (req, res) => {
  const { code } = req.body;

  try {
    const response = await axios.post("https://www.strava.com/oauth/token", {
      client_id: CLIENT_ID,
      client_secret: CLIENT_SECRET,
      code,
      grant_type: "authorization_code"
    });

    res.json(response.data); // access_token, refresh_token, athlete
  } catch (err) {
    console.error(err.response?.data || err);
    res.status(500).json({ error: "Failed to authenticate" });
  }
});

// Get recent activities (requires access token)
router.get("/activities", async (req, res) => {
  const { access_token } = req.headers;

  try {
    const response = await axios.get("https://www.strava.com/api/v3/athlete/activities", {
      headers: { Authorization: `Bearer ${access_token}` }
    });

    res.json(response.data);
  } catch (err) {
    console.error(err.response?.data || err);
    res.status(500).json({ error: "Failed to fetch activities" });
  }
});

module.exports = router;
