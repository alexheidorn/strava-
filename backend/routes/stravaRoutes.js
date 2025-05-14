const express = require('express');
const router = express.Router();
const { redirectToStrava, handleOAuthCallback, getActivities } = require('../controllers/stravaController');

router.get('/login', redirectToStrava);
router.get('/callback', handleOAuthCallback);
router.get('/activities', getActivities);

module.exports = router;
