SELECT
  Websites.id,
  Websites.name,
  access_log.count,
  access_log.date
FROM
  Websites INNER JOIN access_log ON Websites.id=access_log.site_id;