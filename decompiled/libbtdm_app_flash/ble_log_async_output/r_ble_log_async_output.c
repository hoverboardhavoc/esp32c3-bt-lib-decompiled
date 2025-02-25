/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> ble_log_async_output.o -> r_ble_log_async_output
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_ble_log_async_output(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint auStack_44 [4];
  
  cVar2 = *_ble_log_env;
  uVar3 = 0;
  while (cVar2 != '\0') {
    uVar3 = uVar3 + 1 & 0xff;
    cVar2 = cVar2 >> 1;
    if (2 < uVar3) {
      r_assert_param(uVar3,3,"ble_log_async_output.c",0x114);
    }
  }
  iVar4 = uVar3 * 4;
  iVar6 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar4);
  if ((*(byte *)(iVar6 + 0x18) & 2) == 0) {
    return;
  }
  if (*(char *)(iVar6 + 0x10) != '\0') {
    r_assert_param(*(undefined4 *)(iVar6 + 0xc),*(undefined4 *)(param_2 + 4),
                   "ble_log_async_output.c",0x11c);
  }
  pcVar1 = _ble_log_async_env;
  puVar8 = *(uint **)(*(int *)(_ble_log_async_env + 0xc) + iVar4);
  *(undefined1 *)(puVar8 + 4) = 1;
  uVar9 = *puVar8;
  uVar3 = puVar8[1];
  puVar8[3] = *(uint *)(param_2 + 4);
  uVar10 = puVar8[2];
  auStack_44[0] = param_1 + 2;
  if ((param_3 != 0) && (param_4 != 0)) {
    auStack_44[0] = auStack_44[0] + param_3;
  }
  uVar11 = auStack_44[0] & 0xffff;
  if (*pcVar1 == '\0') {
    uVar7 = uVar3 - uVar9;
    if (uVar3 <= uVar9) {
      uVar7 = (uVar3 + uVar10) - uVar9;
    }
    if (uVar7 <= uVar11) {
      uVar7 = puVar8[5];
      do {
        iVar6 = ble_log_async_length_get(uVar7,uVar3,uVar10);
        uVar3 = uVar3 + iVar6;
        if (uVar10 <= uVar3) {
          uVar3 = uVar3 - uVar10;
        }
        iVar6 = uVar10 - uVar9;
        if (uVar9 < uVar3) {
          iVar6 = -uVar9;
        }
      } while (iVar6 + uVar3 <= uVar11);
      puVar8[1] = uVar3;
    }
  }
  else {
    if (uVar3 <= uVar9) {
      uVar3 = uVar3 + uVar10;
    }
    if (uVar3 - uVar9 <= uVar11) goto _L65;
  }
  uVar5 = ble_log_async_addr_copy(uVar10,puVar8[5],uVar9,auStack_44,2);
  uVar3 = ble_log_async_addr_copy(uVar10,puVar8[5],uVar5,param_2,param_1);
  if ((param_3 != 0) && (param_4 != 0)) {
    if (param_5 == 1) {
      uVar3 = 0;
    }
    else {
      uVar3 = ble_log_async_addr_copy(uVar10,puVar8[5],uVar3,param_4,param_3);
    }
  }
  *puVar8 = uVar3;
_L65:
  *(undefined1 *)(*(int *)(iVar4 + *(int *)(_ble_log_async_env + 0xc)) + 0x10) = 0;
  return;
}

