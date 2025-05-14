import axios from 'axios';

export default axios.create({
  baseURL: '/api', // nginx will proxy /api to backend
});
