/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> rwip_driver.o -> r_rwip_aes_encrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwip_aes_encrypt(undefined4 *param_1,void *param_2)

{
  void *__dest;
  
  r_rwip_prevent_sleep_set(0x20);
  __dest = (void *)r_emi_get_mem_addr_by_offset(0x128);
  memcpy(__dest,param_2,0x10);
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  _DAT_600310b4 = *param_1;
  _DAT_600310b8 = param_1[1];
  _DAT_600310bc = param_1[2];
  _DAT_600310c0 = param_1[3];
  _DAT_600310c4 = 0x128;
  _DAT_60031018 = 0x80;
  if (sdk_cfg_priv_opts != '\0') {
    _DAT_6003138c = 0x80;
  }
  _DAT_6003100c = _DAT_6003100c | 0x80;
  _DAT_600310b0 = _DAT_600310b0 | 1;
                    /* WARNING: Could not recover jumptable at 0x00010ef4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_osi_funcs_p + 0x18))();
  return;
}

