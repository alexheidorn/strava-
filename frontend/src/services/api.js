import axios from 'axios';

export default axios.create({
  baseURL: 'http://localhost:4000', // or wherever your backend is running
});
