/*
 * Last changed at upstream commit 352d001fc7f5d34243047454b3f9e684577ce3e0
 * https://github.com/espressif/esp32c3-bt-lib/commit/352d001fc7f5d34243047454b3f9e684577ce3e0
 * Upstream date: 2021-04-20 15:58:00 +0800
 * Upstream subject: ESP32C3, ESP32S3: update libbtdm_app.a(47235b66)
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
  (**(code **)(_r_ip_funcs_p + 0x80))(&_LANCHOR0,3,*(code **)(_r_ip_funcs_p + 0x80));
  (**(code **)(_r_ip_funcs_p + 0x80))(&_LANCHOR1,4,*(code **)(_r_ip_funcs_p + 0x80));
  (**(code **)(_r_ip_funcs_p + 0xc0))(*(code **)(_r_ip_funcs_p + 0xc0));
_L4:
  (**(code **)(_r_ip_funcs_p + 0x54))(param_1,*(code **)(_r_ip_funcs_p + 0x54));
                    /* WARNING: Could not recover jumptable at 0x00010030. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0xa8))();
  return;
}

