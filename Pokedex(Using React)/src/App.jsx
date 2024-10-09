import { Link } from 'react-router-dom'
import './App.css'
import CustomRoutes from './routes/CustomRoutes'

function App() {

  return (
    <>
      <h1 className="main-heading">
        <Link className='headingLink Link' to='/Pokedex'>Pokedex</Link>
        </h1>
      <CustomRoutes/>
    </>
  )
}

export default App
