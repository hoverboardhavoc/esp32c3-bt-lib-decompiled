/*
 * Last changed at upstream commit e668c2d101ee46ee1950819607694fb852aecae0
 * https://github.com/espressif/esp32c3-bt-lib/commit/e668c2d101ee46ee1950819607694fb852aecae0
 * Upstream date: 2025-03-14 11:07:43 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(6e312587)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_construct(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  
  iVar2 = *(int *)(&lld_adv_env + param_1 * 4);
  bVar1 = *(byte *)(iVar2 + 0x74);
  uVar3 = r_lld_ch_idx_get_hack();
  *(undefined1 *)(iVar2 + 0x91) = uVar3;
  *(undefined2 *)(iVar2 + 0x7a) = 0;
  *(undefined2 *)(iVar2 + 0x7c) = 0;
  *(undefined4 *)(iVar2 + 0x6c) = 0;
  if ((bVar1 & 3) == 0) {
    r_lld_adv_ext_chain_none_construct(param_1);
  }
  else if ((bVar1 & 1) == 0) {
    if ((bVar1 & 2) == 0) {
      r_assert_err(0,"lld_adv.c",0x667);
    }
    else {
      r_lld_adv_ext_chain_scannable_construct(param_1);
    }
  }
  else {
    r_lld_adv_ext_chain_connectable_construct(param_1);
  }
  *(uint *)(*(int *)(&lld_adv_env + param_1 * 4) + 0x10) =
       *(int *)(iVar2 + 0x6c) * 2 + (uint)_sdk_cfg_priv_opts;
  return;
}

