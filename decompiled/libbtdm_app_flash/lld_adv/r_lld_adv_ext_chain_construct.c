/*
 * Last changed at upstream commit 2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * https://github.com/espressif/esp32c3-bt-lib/commit/2ce747aec8008d008fe34fa375a2aea3e7e48e9a
 * Upstream date: 2025-02-25 15:16:47 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(723439d)
 * Source: libbtdm_app_flash -> lld_adv.o -> r_lld_adv_ext_chain_construct
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_adv_ext_chain_construct(uint param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
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
      r_assert_err(0,"lld_adv.c",0x678);
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
  iVar4 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar4 + 0x28) & 4) != 0) {
    iVar4 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar4 + 0x2c) < 3) {
      r_ble_log_internal_x2
                (0x40c00013,
                 (uint)*(byte *)(iVar2 + 0x92) << 0x10 | (uint)*(byte *)(iVar2 + 0x91) << 8 |
                 param_1,*(undefined4 *)(iVar2 + 0x6c));
      return;
    }
  }
  return;
}

