/*
 * Last changed at upstream commit 393ac4c33b419226aac9d1e8f1b5d553b7f3bc97
 * https://github.com/espressif/esp32c3-bt-lib/commit/393ac4c33b419226aac9d1e8f1b5d553b7f3bc97
 * Upstream date: 2023-12-19 16:42:02 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(b877d666)
 * Source: libbtdm_app -> rwble.o -> bb_int_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bb_int_init(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar1 + 0x11) != '\0') {
    iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
    if ((*(byte *)(iVar1 + 0x11) & 4) == 0) {
      bb_hw_intr_set(0x10400);
    }
    else {
      _DAT_600118fc = _DAT_600118fc | 0x8000000;
    }
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if ((*(char *)(iVar1 + 0x19) != '\x01') && (sdk_cfg_priv_opts == '\0')) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010312. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x120))(param_1);
  return;
}

