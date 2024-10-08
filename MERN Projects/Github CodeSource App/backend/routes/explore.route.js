import express from "express";
import { explorePopularRepos } from "../controllers/explore.controller.js";

const router = express.Router();

router.get("/repos/:language", explorePopularRepos);

export default router;
