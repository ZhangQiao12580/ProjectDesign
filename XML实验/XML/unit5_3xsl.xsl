<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
	<xsl:template match="/">
		<html>
			<head>
				<title>PRODUCTION LIST</title>
			</head>
			<body>
				<h1>PRODUCTION LIST</h1>
				<table border="1">
					<tbody>
						<tr>
							<td bgcolor="green">PRODID</td>
							<td bgcolor="green">CATEGORY</td>
							<td bgcolor="red">PRODUCTIONNAME</td>
							<td bgcolor="green">DESCERIPTION</td>
							<td bgcolor="green">PRICE</td>
							<td bgcolor="green">QUANTITY</td>
						</tr>
						<xsl:for-each select="//PRODUCT">
							<tr>
								<td bgcolor="green"><xsl:value-of select="@PRODID"/></td>
								<td bgcolor="green"><xsl:value-of select="@CATEGORY"/></td>
								<td bgcolor="red"><xsl:value-of select="PRODUCTNAME"/></td>
								<td bgcolor="green"><xsl:value-of select="DESCRIPTION"/></td>
								<td bgcolor="green"><xsl:value-of select="PRICE"/></td>
								<td bgcolor="green"><xsl:value-of select="QUANTITY"/></td>
							</tr>
						</xsl:for-each>
					</tbody>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
