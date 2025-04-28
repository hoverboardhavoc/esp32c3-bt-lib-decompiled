/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint auStack_44 [4];
  
  cVar2 = *_ble_log_env;
  uVar7 = 0;
  while (cVar2 != '\0') {
    uVar7 = uVar7 + 1 & 0xff;
    cVar2 = cVar2 >> 1;
    if (2 < uVar7) {
      r_assert_param(uVar7,3,"ble_log_async_output.c",0x114);
    }
  }
  iVar8 = uVar7 * 4;
  iVar5 = *(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar8);
  if ((*(byte *)(iVar5 + 0x18) & 2) == 0) {
    return;
  }
  if (*(char *)(iVar5 + 0x10) != '\0') {
    r_assert_param(*(undefined4 *)(iVar5 + 0xc),*(undefined4 *)(param_2 + 4),
                   "ble_log_async_output.c",0x11c);
  }
  pcVar1 = _ble_log_async_env;
  auStack_44[0] = param_1 + 2;
  puVar9 = *(uint **)(*(int *)(_ble_log_async_env + 0xc) + iVar8);
  *(undefined1 *)(puVar9 + 4) = 1;
  uVar10 = *puVar9;
  uVar7 = puVar9[1];
  puVar9[3] = *(uint *)(param_2 + 4);
  uVar11 = puVar9[2];
  if ((param_3 != 0) && (param_4 != 0)) {
    auStack_44[0] = auStack_44[0] + param_3;
  }
  uVar3 = auStack_44[0] & 0xffff;
  if (*pcVar1 == '\0') {
    uVar6 = uVar7 - uVar10;
    if (uVar7 <= uVar10) {
      uVar6 = (uVar7 + uVar11) - uVar10;
    }
    if (uVar6 <= uVar3) {
      uVar6 = puVar9[5];
      do {
        iVar5 = ble_log_async_length_get(uVar6,uVar7,uVar11);
        uVar7 = uVar7 + iVar5;
        if (uVar11 <= uVar7) {
          uVar7 = uVar7 - uVar11;
        }
        iVar5 = uVar11 - uVar10;
        if (uVar10 < uVar7) {
          iVar5 = -uVar10;
        }
      } while (iVar5 + uVar7 <= uVar3);
      puVar9[1] = uVar7;
    }
  }
  else {
    if (uVar7 <= uVar10) {
      uVar7 = uVar7 + uVar11;
    }
    if (uVar7 - uVar10 <= uVar3) goto _L62;
  }
  uVar4 = ble_log_async_addr_copy(uVar11,puVar9[5],uVar10,auStack_44,2);
  uVar7 = ble_log_async_addr_copy(uVar11,puVar9[5],uVar4,param_2,param_1);
  if ((param_3 != 0) && (param_4 != 0)) {
    if (param_5 == 1) {
      uVar7 = 0;
    }
    else {
      uVar7 = ble_log_async_addr_copy(uVar11,puVar9[5],param_4,param_3);
    }
  }
  *puVar9 = uVar7;
_L62:
  *(undefined1 *)(*(int *)(*(int *)(_ble_log_async_env + 0xc) + iVar8) + 0x10) = 0;
  return;
}

