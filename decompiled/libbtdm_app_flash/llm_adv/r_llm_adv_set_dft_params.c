/*
 * Last changed at upstream commit 16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * https://github.com/espressif/esp32c3-bt-lib/commit/16cda80aab0a008093592b7e304c77dcb3ac9ea4
 * Upstream date: 2025-12-31 14:03:52 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(1bb2f50)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_set_dft_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_dft_params(uint param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uStack_2c;
  uint uStack_28;
  undefined4 uStack_24;
  
  iVar2 = param_1 * 0x44;
  if (*(int *)(*(int *)(_p_llm_env + 8) + iVar2) != 0) {
    r_assert_err(0,"llm_adv.c",0xcdc);
  }
  iVar4 = *(int *)(_p_llm_env + 8);
  uVar3 = r_ke_msg_alloc(0,0,0,0x1a);
  *(undefined4 *)(iVar4 + iVar2) = uVar3;
  iVar4 = _p_llm_env;
  puVar1 = *(undefined1 **)(*(int *)(_p_llm_env + 8) + iVar2);
  *puVar1 = 0xff;
  *(undefined2 *)(puVar1 + 2) = 0x13;
  *(undefined2 *)(puVar1 + 4) = 0x800;
  *(undefined2 *)(puVar1 + 8) = 8;
  *(undefined2 *)(puVar1 + 10) = 7;
  *(undefined2 *)(puVar1 + 6) = 0;
  puVar1[0xc] = 0;
  memset(puVar1 + 0xd,0,6);
  *(undefined2 *)(puVar1 + 0x14) = 0x17f;
  puVar1[0x13] = 0;
  *(undefined2 *)(puVar1 + 0x16) = 0x100;
  *(undefined2 *)(puVar1 + 0x18) = 0;
  iVar2 = *(int *)(iVar4 + 8) + iVar2;
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar4 + 0xc);
  *(undefined2 *)(iVar2 + 8) = *(undefined2 *)(iVar4 + 0x10);
  *(undefined1 *)(iVar2 + 0x40) = 1;
  r_ble_log_internal_x1(0x404e0199,param_1 | 0x100);
  if ((_bt_rf_coex_hooks_p != 0) && (*(code **)(_bt_rf_coex_hooks_p + 4) != (code *)0x0)) {
    uStack_24 = 0;
    uStack_2c = (uint)(byte)puVar1[8] << 8 | (uint)(byte)puVar1[7] << 0x10 | (uint)(byte)puVar1[7];
    uStack_28 = (uint)(byte)puVar1[10];
    (**(code **)(_bt_rf_coex_hooks_p + 4))(param_1,0,&uStack_2c);
  }
  return;
}

