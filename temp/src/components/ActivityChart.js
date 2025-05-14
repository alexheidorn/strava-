import React, { useEffect, useState } from 'react';
import { LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, ResponsiveContainer } from 'recharts';
import axios from '../services/api';

const ActivityChart = () => {
  const [data, setData] = useState([]);

  useEffect(() => {
    axios.get('/activities').then((res) => {
      const formatted = res.data.map(activity => ({
        date: new Date(activity.start_date).toLocaleDateString(),
        distance: (activity.distance / 1000).toFixed(2), // km
      }));
      setData(formatted);
    });
  }, []);

  return (
    <div>
      <h2>Distance Over Time</h2>
      <ResponsiveContainer width="100%" height={400}>
        <LineChart data={data}>
          <CartesianGrid strokeDasharray="3 3" />
          <XAxis dataKey="date" />
          <YAxis label={{ value: 'Distance (km)', angle: -90, position: 'insideLeft' }} />
          <Tooltip />
          <Line type="monotone" dataKey="distance" stroke="#8884d8" />
        </LineChart>
      </ResponsiveContainer>
    </div>
  );
};

export default ActivityChart;
