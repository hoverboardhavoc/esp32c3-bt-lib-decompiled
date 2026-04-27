/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_instant_proc_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_instant_proc_end(uint param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  r_ble_log_internal_x1(0x40a3010b,(uint)*(byte *)(iVar2 + 0x46) << 8 | param_1);
  cVar1 = *(char *)(iVar2 + 0x46);
  if (cVar1 == '\x02') {
    uVar3 = 0x210;
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        r_ke_msg_send_basic(0x20f,param_1 << 8 | 1,0xff);
        r_lld_con_evt_time_update_eco(param_1);
        r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100));
      }
      else {
        r_assert_warn(0,0,"lld_con.c",0x8f0);
      }
      goto _L265;
    }
    *(undefined1 *)(iVar2 + 0x93) = *(undefined1 *)(iVar2 + 0x35);
    *(undefined1 *)(iVar2 + 0x94) = *(undefined1 *)(iVar2 + 0x34);
    r_lld_con_evt_time_update_eco(param_1);
    r_lld_con_tx_len_update(param_1,*(undefined1 *)(iVar2 + 0x94),*(undefined4 *)(iVar2 + 100));
    uVar3 = 0x211;
  }
  r_ke_msg_send_basic(uVar3,param_1 << 8 | 1,0xff);
_L265:
  *(undefined1 *)(iVar2 + 0x46) = 0;
  return;
}

