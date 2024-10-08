import express from "express";
import { getUserProfileAndRepos } from "../controllers/user.controller.js";

const router = express.Router();

router.get("/profile/:username", getUserProfileAndRepos);
// ToDo  =>  GET likes (likes Routes-- who likes our profile  )
// ToDo  => POST  like a profile  (like a profile  Routes )

export default router;
