/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_env_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_ble_log_async_env_init(uint param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  void *__s;
  size_t __n;
  int iVar5;
  
  _ble_log_async_env =
       (undefined1 *)(**(code **)(_r_osi_funcs_p + 0x74))(0x10,*(code **)(_r_osi_funcs_p + 0x74));
  if (_ble_log_async_env != (undefined1 *)0x0) {
    memset(_ble_log_async_env,0,0x10);
    puVar1 = _ble_log_async_env;
    uVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(300,*(code **)(_r_osi_funcs_p + 0x74));
    puVar2 = _ble_log_async_env;
    *(undefined4 *)(puVar1 + 8) = uVar4;
    if (*(void **)(puVar2 + 8) != (void *)0x0) {
      memset(*(void **)(puVar2 + 8),0,300);
      puVar1 = _ble_log_async_env;
      uVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(0xc,*(code **)(_r_osi_funcs_p + 0x74));
      puVar2 = _ble_log_async_env;
      *(undefined4 *)(puVar1 + 0xc) = uVar4;
      if (*(void **)(puVar2 + 0xc) != (void *)0x0) {
        memset(*(void **)(puVar2 + 0xc),0,0xc);
        puVar1 = _ble_log_async_env;
        iVar3 = 0;
        *(undefined4 *)(_ble_log_async_env + 4) = 0;
        *puVar1 = 0;
        while( true ) {
          iVar5 = *(int *)(_ble_log_async_env + 0xc);
          uVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(0x1c,*(code **)(_r_osi_funcs_p + 0x74));
          puVar1 = _ble_log_async_env;
          *(undefined4 *)(iVar5 + iVar3) = uVar4;
          if (*(void **)(*(int *)(puVar1 + 0xc) + iVar3) == (void *)0x0) break;
          memset(*(void **)(*(int *)(puVar1 + 0xc) + iVar3),0,0x1c);
          if ((param_1 & 1) == 0) {
            iVar5 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3);
            *(undefined4 *)(iVar5 + 8) = 0;
            *(byte *)(iVar5 + 0x18) = *(byte *)(iVar5 + 0x18) & 0xfc;
          }
          else {
            iVar5 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3);
            *(byte *)(iVar5 + 0x18) = *(byte *)(iVar5 + 0x18) & 0xfc | 3;
            *(undefined4 *)(iVar5 + 8) = *(undefined4 *)(param_2 + iVar3);
          }
          iVar3 = iVar3 + 4;
          if (iVar3 == 0xc) {
            iVar3 = 0;
            goto _L156;
          }
          param_1 = param_1 >> 1;
        }
      }
    }
  }
_L152:
  r_ble_log_async_env_deinit();
  return 0xffffffff;
_L156:
  iVar5 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3);
  if ((*(byte *)(iVar5 + 0x18) & 2) == 0) {
    *(undefined4 *)(iVar5 + 8) = 0;
    *(undefined4 *)(iVar5 + 0x14) = 0;
    *(byte *)(iVar5 + 0x18) = *(byte *)(iVar5 + 0x18) & 0xfc;
  }
  else {
    __n = *(size_t *)(iVar5 + 8);
    uVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(__n,*(code **)(_r_osi_funcs_p + 0x74));
    puVar1 = _ble_log_async_env;
    *(undefined4 *)(iVar5 + 0x14) = uVar4;
    __s = *(void **)(*(int *)(*(int *)(puVar1 + 0xc) + iVar3) + 0x14);
    if (__s == (void *)0x0) goto _L152;
    memset(__s,0,__n);
  }
  iVar3 = iVar3 + 4;
  if (iVar3 == 0xc) {
    return 0;
  }
  goto _L156;
}

