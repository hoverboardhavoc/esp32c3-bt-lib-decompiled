/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar2 = _DAT_60031010;
  if (DAT_00011045 != '\0') {
    if ((int)(_DAT_60031010 << 9) < 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      if ((*(int *)(iVar4 + 0x28) << 0x14 < 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 4)) {
        r_ble_log_internal_x1(0x60270001,uVar2);
      }
      _DAT_600312d8 = _DAT_600312d8 | 0x80000000;
      _DAT_60031018 = 0x7fffff;
      if ((uVar2 & 0x1fffff) == 1) {
        if (1 < _g_bt_plf_log_level) {
          ets_printf("IRQ FIFO OVERFLOW\n");
        }
      }
      else {
        r_assert_err(0,"rwble.c",0x1a6);
      }
    }
    uVar3 = _DAT_600312d8;
    if ((int)(uVar2 << 10) < 0) {
      iVar4 = r_sdk_config_get_opts_ext();
      uVar1 = uVar3 >> 5 & 0x1f;
      uVar3 = uVar3 >> 1 & 0xf;
      if ((*(int *)(iVar4 + 0x28) << 0x14 < 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 4)) {
        r_ble_log_internal_x2(0x60270002,uVar3 << 8 | uVar1,uVar2);
      }
      _DAT_60031018 = _DAT_60031018 | 0x200000;
      if (1 < _g_bt_plf_log_level) {
        ets_printf("IRQ FIFO ALMOST FULL,cnt:%u,rem:%u\n",uVar1,uVar3);
      }
    }
  }
_L85:
  if (DAT_00011045 == '\0') {
    uVar2 = _DAT_60031010;
    if (_DAT_60031010 != 0) goto _L89;
  }
  else {
    uVar2 = _DAT_600312d8 >> 10 & 0x1fffff;
    if ((_DAT_600312d8 >> 5 & 0x1f) != 0) goto code_r0x000104ca;
  }
  return;
code_r0x000104ca:
  _DAT_600312d8 = _DAT_600312d8 | 1;
  if (uVar2 != 0) {
_L89:
    if ((uVar2 & 0x81e89) != 0) {
      r_rwip_isr(uVar2);
    }
    if ((uVar2 & 0x100) != 0) {
      _DAT_60031018 = 0x100;
      iVar4 = r_sdk_config_get_opts_ext();
      if ((*(int *)(iVar4 + 0x28) << 0x14 < 0) &&
         (iVar4 = r_sdk_config_get_opts_ext(), *(byte *)(iVar4 + 0x2c) < 5)) {
        r_ble_log_internal_x1(0x80270000,uVar2);
      }
      iVar4 = r_rwble_isr_hw_fixed(_DAT_60031060);
      if (iVar4 != 0) {
        _DAT_60031050 = 0x838295a8;
        if ((0 < _g_bt_plf_log_level) &&
           (ets_printf(__c_3,_DAT_60031054,_DAT_60031054), 0 < _g_bt_plf_log_level)) {
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
        r_assert_param(_DAT_60031060,0,"rwble.c",0x1f6);
      }
    }
    if ((uVar2 & 2) != 0) {
      _DAT_60031018 = 2;
      r_sch_prog_tx_isr(0xff);
    }
    if ((uVar2 & 4) != 0) {
      _DAT_60031018 = 4;
      r_sch_prog_rx_isr(0xff);
    }
    if ((int)(uVar2 << 0xd) < 0) {
      _DAT_60031018 = _DAT_60031018 | 0x40000;
      r_lld_update_rxbuf_isr();
    }
    if ((uVar2 & 0x40) != 0) {
      _DAT_60031018 = 0x40;
      r_sch_prog_skip_isr(0xff);
    }
    if ((uVar2 & 0x20) != 0) {
      _DAT_60031018 = 0x20;
      r_sch_prog_end_isr(0xff);
    }
  }
  goto _L85;
}

