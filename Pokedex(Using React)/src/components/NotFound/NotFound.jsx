import React from 'react';
import Card from 'react-bootstrap/Card';
import './NotFound.css';

function NotFound() {
    return (
        <div className="notFoundContainer">
            <Card className='notFoundCard'>
                <Card.Body>
                    <Card.Title>Pokemon Not Found</Card.Title>
                    <Card.Text>
                        It looks like the Pokemon you are looking for doesn't exist. Please check the spelling and try again.
                    </Card.Text>
                </Card.Body>
            </Card>
        </div>
    );
}

export default NotFound;