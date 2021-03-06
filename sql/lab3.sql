 SELECT EMP1.EMPNO AS "Employee Number", EMP1.ENAME AS "Employee Name", EMP1.HIREDATE AS "HIredate", EMP2.ENAME AS "Manager"
  FROM EMP EMP1
  INNER JOIN EMP EMP2
  ON EMP1.MGR  = EMP2.EMPNO
  WHERE EMP2.ENAME LIKE 'K%'
  OR EMP2.ENAME LIKE 'M%'
  OR EMP2.ENAME LIKE 'S%';


 SELECT E.ENAME AS "Employee Name", E.EMPNO, C.EMPNO, D.DEPTNO AS "Department Num", D.DNAME AS "Department Name"
   FROM EMP E
   INNER JOIN DEPT D
   ON E.DEPTNO = D.DEPTNO
   INNER JOIN EMP C
   ON E.EMPNO <> C.EMPNO
   ORDER BY E.ENAME, D.DEPTNO, D.DNAME;


 SELECT EMP.ENAME, EMP.JOB, EMP.DEPTNO, DEPT.LOC
  FROM EMP
  INNER JOIN DEPT
  ON EMP.DEPTNO = DEPT.DEPTNO
  WHERE EMP.JOB LIKE 'CLERK%';

 INSERT INTO DEPT (DEPTNO, DNAME, LOC)
  VALUES (50, 'TRAINING', 'SAN FRANCISCO');

SELECT EMP.EMPNO, EMP.ENAME, DEPT.DNAME, DEPT.LOC
  FROM EMP
  RIGHT JOIN DEPT
  ON EMP.DEPTNO = DEPT.DEPTNO
  WHERE DEPT.DEPTNO LIKE '50%'
  OR DEPT.DEPTNO LIKE '20%';

 INSERT INTO EMP2 (EMPNO, ENAME, JOB, MGR, HIREDATE, SAL, COMM)
  VALUES (7612, 'LEBEDEV', 'MANAGER', 7839, '31-DEC-1980', 2975, 0);

SELECT EMP2.EMPNO, EMP2.ENAME, DEPT.DEPTNO, DEPT.DNAME, DEPT.LOC
  FROM EMP2
  FULL OUTER JOIN DEPT
  ON EMP2.DEPTNO = DEPT.DEPTNO;







