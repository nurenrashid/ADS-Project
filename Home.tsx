import { useNavigate } from "react-router-dom";
import "./ViewTables.css";

function Home() {
  const navigate = useNavigate();

  return (
    <div className="home">
      <h1>
        🍽️ Food Court
        <br />
        Table Tracker
      </h1>

      <p className="welcome">Welcome back!</p>

      <button onClick={() => navigate("/viewtables")}>
        📋 View Tables
      </button>

      <button onClick={() => navigate("/search")}>
        🔍 Search Table
      </button>

      <button onClick={() => navigate("/capacity")}>
        👥 Search by Capacity
      </button>

      <button onClick={() => navigate("/checkin")}>
        ✅ Check In
      </button>

      <button onClick={() => navigate("/checkout")}>
        🚪 Check Out
      </button>

      <button onClick={() => navigate("/statistics")}>
        📊 Statistics
      </button>

      <button onClick={() => navigate("/history")}>
        🕒 History
      </button>
    </div>
  );
}

export default Home;