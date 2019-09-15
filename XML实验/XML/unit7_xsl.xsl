<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
	<xsl:template match="/">
	<html>
		<head>
			<title>百度一下，你就知道</title>
		</head>
		<body>
			<xsl:for-each select="links/link">
				<a>
					<xsl:attribute name="href">
						<xsl:value-of select="@xlink:href"/>
					</xsl:attribute>
					<xsl:attribute name="target">
						<xsl:value-of select="@xlink:show"/>
					</xsl:attribute>
					<xsl:value-of select="name"/>
				</a>
			</xsl:for-each>
		</body>
	</html>
		
	</xsl:template>
</xsl:stylesheet>
