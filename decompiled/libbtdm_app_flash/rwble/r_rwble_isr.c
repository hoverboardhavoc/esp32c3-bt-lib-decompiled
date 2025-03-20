/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
 * Source: libbtdm_app_flash -> rwble.o -> r_rwble_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_rwble_isr(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = _DAT_60031010;
  if (DAT_00011045 != '\0') {
    if ((int)(_DAT_60031010 << 9) < 0) {
      _DAT_600312d8 = _DAT_600312d8 | 0x80000000;
      _DAT_60031018 = 0x7fffff;
      if ((_DAT_60031010 & 0x1fffff) == 1) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("IRQ FIFO OVERFLOW\n");
        }
      }
      else {
        r_assert_err(0,"rwble.c",0x1a5);
      }
    }
    if (((int)(uVar1 << 10) < 0) &&
       (_DAT_60031018 = _DAT_60031018 & 0xffdfffff | 0x200000, 1 < _g_bt_plf_log_level)) {
      ets_printf("IRQ FIFO ALMOST FULL,cnt:%u,rem:%u\n",_DAT_600312d8 >> 5 & 0x1f,
                 _DAT_600312d8 >> 1 & 0xf);
    }
  }
_L79:
  if (DAT_00011045 == '\0') {
    uVar1 = _DAT_60031010;
    if (_DAT_60031010 != 0) goto _L83;
  }
  else {
    uVar1 = (_DAT_600312d8 << 1) >> 0xb;
    if ((_DAT_600312d8 >> 5 & 0x1f) != 0) goto code_r0x00010438;
  }
  return;
code_r0x00010438:
  _DAT_600312d8 = _DAT_600312d8 | 1;
  if (uVar1 != 0) {
_L83:
    if ((uVar1 & 0x81e89) != 0) {
      r_rwip_isr(uVar1);
    }
    if ((uVar1 & 0x100) != 0) {
      _DAT_60031018 = 0x100;
      iVar2 = r_rwble_isr_hw_fixed(_DAT_60031060);
      if (iVar2 != 0) {
        _DAT_60031050 = 0x838295a8;
        if ((0 < _g_bt_plf_log_level) &&
           (ets_printf("DIAG0~1:%08x,%08x\n",_DAT_60031054,_DAT_60031054), 0 < _g_bt_plf_log_level))
        {
          ets_printf("BB DIAG0~5:%08x,%08x,%08x,%08x,%08x,%08x\n",_DAT_6001106c,_DAT_60011070,
                     _DAT_60011074,_DAT_60011078,_DAT_6001107c,_DAT_60011080);
        }
        if (_DAT_60031060 << 10 < 0) {
          if (0 < _g_bt_plf_log_level) {
            ets_printf("EM BASE ERR:%02x\n",_DAT_600312cc & 0x3fff);
          }
          r_emi_em_base_reg_show();
          r_emi_base_reg_lut_show();
        }
        if ((_DAT_60031060 << 9 < 0) && (0 < _g_bt_plf_log_level)) {
          ets_printf("FSMERR:%08x\n",_DAT_600312dc);
        }
        r_assert_param(_DAT_60031060,0,"rwble.c",499);
      }
    }
    if ((uVar1 & 2) != 0) {
      _DAT_60031018 = 2;
      r_sch_prog_tx_isr(0xff);
    }
    if ((uVar1 & 4) != 0) {
      _DAT_60031018 = 4;
      r_sch_prog_rx_isr(0xff);
    }
    if ((int)(uVar1 << 0xd) < 0) {
      _DAT_60031018 = _DAT_60031018 & 0xfffbffff | 0x40000;
      r_lld_update_rxbuf_isr();
    }
    if ((uVar1 & 0x40) != 0) {
      _DAT_60031018 = 0x40;
      r_sch_prog_skip_isr(0xff);
    }
    if ((uVar1 & 0x20) != 0) {
      _DAT_60031018 = 0x20;
      r_sch_prog_end_isr(0xff);
    }
  }
  goto _L79;
}

