/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app -> lld.o -> r_lld_update_rxbuf_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_update_rxbuf_isr(void)

{
  if (3 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update ISR  %04x %04x\n",_DAT_600312d0 & 0x7fff,_DAT_60031024 & 0x7fff);
  }
  _DAT_600312d0 = _DAT_600312d0 & 0xffff7fff;
                    /* WARNING: Could not recover jumptable at 0x00012c4a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0xe4))(0x215,1,0xff);
  return;
}

