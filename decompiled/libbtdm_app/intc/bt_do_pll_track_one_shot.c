/*
 * Last changed at upstream commit 2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * https://github.com/espressif/esp32c3-bt-lib/commit/2a91d90e33b3b1104daf1bff898fe5bc3f814811
 * Upstream date: 2022-09-07 12:18:28 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(2ee0168e)
 * Source: libbtdm_app -> intc.o -> bt_do_pll_track_one_shot
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_do_pll_track_one_shot(void)

{
  uint uVar1;
  int iVar2;
  
  bt_track_pll_cap();
  iVar2 = sdk_config_get_opts_ext();
  uVar1 = 0x18000;
  if (*(char *)(iVar2 + 0x11) != '\0') {
    uVar1 = 0x8000;
  }
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  _DAT_60011084 = ~uVar1 & _DAT_60011084;
  _LANCHOR0 = 0;
                    /* WARNING: Could not recover jumptable at 0x000101e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

