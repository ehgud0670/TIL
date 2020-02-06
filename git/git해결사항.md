# Git 해결사항

> 상황 명시 : codesquad에 pull request를 보내고, merge를 받은 상황이다. 

* 이후 내가 해야 할 일 

'ehgud0670'은 나의 대표 브랜치, 'upstream'은 JK의 리모트 저장소이다.  

```
% git checkout ehgud0670
% git fetch upstream
% git rebase upstream/ehgud0670
```

지금 위의 상황을 말해보자면...

나의 로컬 저장소의 ehgud0670 브랜치와 리모트 저장소인 upstream/ehgud0670 은 동기화(sync)가 되어있는 상태이고, **내가 fork 한 나의 리모트 저장소인 origin은 동기화가 안되어 있는 상태이다!!**

```
git push origin ehgud0670 
```
브랜치 ehgud0670으로 origin 원격 저장소에 push하면 드디어 **로컬 저장소/ehgud0670, upstream/ehgud0670, origin/ehgud0670 이 모두 동기화(sync)** 가 되었다! 