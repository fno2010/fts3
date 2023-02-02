--
-- FTS3 Schema 8.1.0
-- [FTS-XXXX] Schema changes for admission control feature
--

DROP TABLE IF EXISTS `t_admission_control`;

CREATE TABLE `t_admission_control` (
    `source_se` varchar(150) NOT NULL,
    `dest_se` varchar(150) NOT NULL,
    `vo_name` varchar(50) NOT NULL,
    `svc_rate` double DEFAULT NULL,
    PRIMARY KEY (`source_se`, `dest_se`, `vo_name`),
)

INSERT INTO t_schema_vers (major, minor, patch, message)
VALUES (8, 1, 0, 'FTS-XXXX: Schema changes for admission control feature');
