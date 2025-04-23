/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  byte bVar5;
  int iVar6;
  
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
          iVar6 = *(int *)(_ble_log_async_env + 0xc);
          uVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(0x1c,*(code **)(_r_osi_funcs_p + 0x74));
          puVar1 = _ble_log_async_env;
          *(undefined4 *)(iVar6 + iVar3) = uVar4;
          if (*(void **)(*(int *)(puVar1 + 0xc) + iVar3) == (void *)0x0) break;
          memset(*(void **)(*(int *)(puVar1 + 0xc) + iVar3),0,0x1c);
          iVar6 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3);
          bVar5 = *(byte *)(iVar6 + 0x18) & 0xfc;
          if ((param_1 & 1) == 0) {
            *(byte *)(iVar6 + 0x18) = bVar5;
            uVar4 = 0;
          }
          else {
            *(byte *)(iVar6 + 0x18) = bVar5 | 3;
            uVar4 = *(undefined4 *)(param_2 + iVar3);
          }
          *(undefined4 *)(iVar6 + 8) = uVar4;
          iVar3 = iVar3 + 4;
          if (iVar3 == 0xc) {
            iVar3 = 0;
            goto _L155;
          }
          param_1 = param_1 >> 1;
        }
      }
    }
  }
_L151:
  r_ble_log_async_env_deinit();
  return 0xffffffff;
_L155:
  iVar6 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar3);
  if ((*(byte *)(iVar6 + 0x18) & 2) == 0) {
    *(undefined4 *)(iVar6 + 8) = 0;
    *(undefined4 *)(iVar6 + 0x14) = 0;
    *(byte *)(iVar6 + 0x18) = *(byte *)(iVar6 + 0x18) & 0xfc;
  }
  else {
    __n = *(size_t *)(iVar6 + 8);
    uVar4 = (**(code **)(_r_osi_funcs_p + 0x74))(__n,*(code **)(_r_osi_funcs_p + 0x74));
    puVar1 = _ble_log_async_env;
    *(undefined4 *)(iVar6 + 0x14) = uVar4;
    __s = *(void **)(*(int *)(*(int *)(puVar1 + 0xc) + iVar3) + 0x14);
    if (__s == (void *)0x0) goto _L151;
    memset(__s,0,__n);
  }
  iVar3 = iVar3 + 4;
  if (iVar3 == 0xc) {
    return 0;
  }
  goto _L155;
}

