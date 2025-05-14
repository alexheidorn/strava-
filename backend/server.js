const express = require("express");
const cors = require("cors");
require("dotenv").config();
const mongoose = require('mongoose');

mongoose.connect(process.env.MONGO_URI, {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => console.log('MongoDB connected'))
  .catch(err => console.error('MongoDB connection error:', err));


const stravaRoutes = require("./routes/stravaRoutes");

const app = express();
app.use(cors());
app.use(express.json());

app.use("/api/strava", stravaRoutes);

const PORT = process.env.PORT || 4000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
