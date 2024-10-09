import { Route, Routes } from "react-router-dom";
import Pokedex from "../components/Pokedex/Pokedex";
import PokemonDetails from "../components/PokemonDetails/PokemonDetails";

function CustomRoutes(){
    
    return(
        <Routes>
            <Route path="/Pokedex" element={<Pokedex/>} />
            <Route path="/Pokedex/:id" element={<PokemonDetails/>} />
        </Routes>
    )
}

export default CustomRoutes;