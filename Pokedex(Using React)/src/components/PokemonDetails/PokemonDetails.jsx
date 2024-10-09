import axios from 'axios';
import { useEffect, useState } from 'react';
import { useParams } from 'react-router-dom';
import Card from 'react-bootstrap/Card';
import "./pokemonDetails.css"
import NotFound from '../NotFound/NotFound';

function PokemonDetails({ pokemonName }){
    const [pokemon, setPokemon] = useState();
    const {id} = useParams();
    const [error, setError] = useState(false);

    const endpoint = pokemonName ? pokemonName.toLowerCase() : id;

    async function getDetails(){
        try{const response = await axios.get(`https://pokeapi.co/api/v2/pokemon/${endpoint}`)
        const pokemonData = response.data
        setPokemon({
            name: pokemonData.name.toUpperCase(),
            exp: pokemonData.base_experience,
            height: pokemonData.height,
            weight: pokemonData.weight,
            moves: pokemonData.moves.map((p) => p.move.name),
            img: pokemonData.sprites.other.dream_world.front_default,
            types: pokemonData.types.map((t) => t.type.name)
        })}
        catch(e){
            setError(true);
        }
    }
    
    useEffect(()=>{
        getDetails()
        window.scrollTo({top: 0, left: 0, behavior: 'smooth'});
    }, [id, pokemonName])

    if (!pokemon && !error) {
        return <div>Loading...</div>;
    }
    if(!pokemon && error){
        return <NotFound/>;
    }
    return(
        <div className="pokemonContainer">
            <Card className='pokemonCard'>
                {pokemon.img && <Card.Img variant="top" src={pokemon.img} />}
                <Card.Body>
                    <Card.Title>{pokemon.name}</Card.Title>
                    <Card.Text>Experience: {pokemon.exp}</Card.Text>
                    <Card.Text>Height: {pokemon.height*10} cm</Card.Text>
                    <Card.Text>Weight: {pokemon.weight} kg</Card.Text>
                    <Card.Text>
                        <strong>Types:</strong> {pokemon.types.join(", ")}
                    </Card.Text>
                    <Card.Text>
                        <strong>Moves:</strong>
                        <ul>
                            {pokemon.moves.slice(0, 10).map((move, index) => (
                                <li key={index}>{move}</li>
                            ))}
                        </ul>
                    </Card.Text>
                </Card.Body>
            </Card>
        </div>
    )
}

export default PokemonDetails;