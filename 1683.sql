SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;

-- side note: LENGTH() might overcount special characters as it shows the length in bytes, CHAR_LENGTH() won't 