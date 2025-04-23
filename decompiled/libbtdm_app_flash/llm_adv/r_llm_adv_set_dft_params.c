/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llm_adv.o -> r_llm_adv_set_dft_params
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llm_adv_set_dft_params(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar3 = param_1 * 0x44;
  if (*(int *)(*(int *)(_p_llm_env + 8) + iVar3) != 0) {
    r_assert_err(0,"llm_adv.c",0xc45);
  }
  iVar5 = *(int *)(_p_llm_env + 8);
  uVar4 = r_ke_msg_alloc(0,0,0,0x1a);
  iVar1 = _p_llm_env;
  *(undefined4 *)(iVar5 + iVar3) = uVar4;
  puVar2 = *(undefined1 **)(*(int *)(iVar1 + 8) + iVar3);
  *puVar2 = 0xff;
  *(undefined2 *)(puVar2 + 2) = 0x13;
  *(undefined2 *)(puVar2 + 8) = 8;
  *(undefined2 *)(puVar2 + 4) = 0x800;
  *(undefined2 *)(puVar2 + 6) = 0;
  *(undefined2 *)(puVar2 + 10) = 7;
  puVar2[0xc] = 0;
  memset(puVar2 + 0xd,0,6);
  *(undefined2 *)(puVar2 + 0x14) = 0x17f;
  puVar2[0x13] = 0;
  *(undefined2 *)(puVar2 + 0x16) = 0x100;
  *(undefined2 *)(puVar2 + 0x18) = 0;
  iVar3 = *(int *)(iVar1 + 8) + iVar3;
  *(undefined4 *)(iVar3 + 4) = *(undefined4 *)(iVar1 + 0xc);
  *(undefined2 *)(iVar3 + 8) = *(undefined2 *)(iVar1 + 0x10);
  *(undefined1 *)(iVar3 + 0x40) = 1;
  if ((_bt_rf_coex_hooks_p != 0) && (*(code **)(_bt_rf_coex_hooks_p + 4) != (code *)0x0)) {
    uStack_24 = 0;
    uStack_2c = 0x800;
    uStack_28 = 7;
    (**(code **)(_bt_rf_coex_hooks_p + 4))(param_1,0,&uStack_2c);
  }
  return;
}

