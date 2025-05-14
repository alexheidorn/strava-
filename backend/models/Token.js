const mongoose = require('mongoose');

const TokenSchema = new mongoose.Schema({
  athleteId: { type: Number, required: true, unique: true },
  accessToken: { type: String, required: true },
  refreshToken: { type: String, required: true },
  expiresAt: { type: Number, required: true } // UNIX timestamp (seconds)
});

module.exports = mongoose.model('Token', TokenSchema);
