--
-- FTS3 Schema 8.1.1
-- Add "t_bound" table for per-pipe resource control specification
--

ALTER TABLE `t_optimizer`
    ADD COLUMN `vo_name` varchar(50) NOT NULL;

ALTER TABLE `t_optimizer`
    DROP PRIMARY KEY;

ALTER TABLE `t_optimizer`
    ADD PRIMARY KEY (`source_se`,`dest_se`,`vo_name`);

ALTER TABLE `t_optimizer_evolution`
    ADD COLUMN `vo_name` varchar(50) NOT NULL;

ALTER TABLE `t_optimizer_evolution`
    DROP KEY `idx_optimizer_evolution` (`source_se`,`dest_se`,`datetime`);

ALTER TABLE `t_optimizer_evolution`
    ADD KEY `idx_optimizer_evolution` (`source_se`,`dest_se`,`vo_name`,`datetime`);

DROP TABLE IF EXISTS `t_bound`;

CREATE TABLE `t_bound` (
    `source_se` varchar(150) NOT NULL,
    `dest_se`   varchar(150) NOT NULL,
    `vo_name`   varchar(50) NOT NULL,
    `proj_id`   varchar(50) NOT NULL,
    `resc_id`  varchar(64) NOT NULL,
    `max_usage` double DEFAULT NULL,
    `max_share` double DEFAULT NULL,
    PRIMARY KEY (`source_se`, `dest_se`, `vo_name`, `resc_id`)
);

INSERT INTO t_schema_vers (major, minor, patch, message)
VALUES (8, 1, 1, 'Add new tables for TCN per-pipe resource control');
