<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format">
	<xsl:template match="/">
		<html>
			<head>
				<title>Order List</title>
			</head>
			<body>
				<h1>Order List</h1>
				<table border="1">
					<tbody>
						<tr>
							<td>name</td>
							<td>number</td>
							<td>city</td>
							<td>zip</td>
							<td>Order-id</td>
							<td>Order-date</td>
						</tr>
						<xsl:for-each select="//Order[city='北京']">
							<tr>
								<td><xsl:value-of select="name"/></td>
								<td><xsl:value-of select="number"/></td>
								<td><xsl:value-of select="city"/></td>
								<td><xsl:value-of select="zip"/></td>
								<td><xsl:value-of select="@orderId"/></td>
								<td><xsl:value-of select="@orderDate"/></td>
							</tr>
						</xsl:for-each>
					</tbody>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
