/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> hci.o -> r_hci_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_hci_init(int param_1)

{
  if (param_1 == 0) {
    hci_ext_host = sdk_cfg_priv_opts ^ 1;
  }
  else if (param_1 != 2) goto _L4;
  memset(&hci_env,0,0x22);
  (**(code **)(_r_ip_funcs_p + 0x80))(&hci_def_evt_msk,3,*(code **)(_r_ip_funcs_p + 0x80));
  (**(code **)(_r_ip_funcs_p + 0x80))(&hci_le_def_evt_msk,4,*(code **)(_r_ip_funcs_p + 0x80));
  (**(code **)(_r_ip_funcs_p + 0xc0))(*(code **)(_r_ip_funcs_p + 0xc0));
_L4:
  (**(code **)(_r_ip_funcs_p + 0x54))(param_1,*(code **)(_r_ip_funcs_p + 0x54));
                    /* WARNING: Could not recover jumptable at 0x00010030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0xa8))(*(code **)(_r_ip_funcs_p + 0xa8));
  return;
}

