/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_update_rxbuf
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_update_rxbuf(uint param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  
  if (((int)param_1 < 0x111) && (param_2 - 1 < 9)) {
    (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
    uVar3 = _DAT_60031024;
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar4 = ((uVar3 & 0x7fff) - 0x1000) / 0x14 & 0xff;
    uVar1 = *(ushort *)(uVar4 * 0x14 + iVar5);
    uVar7 = (*(byte *)(_p_lld_env + 0xd9) + 1) % 10;
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar5 = uVar7 * 0x14;
    if (-1 < *(short *)(iVar6 + iVar5)) {
      r_assert_err(0,"lld.c",0x6fc);
    }
    r_ble_util_buf_set_rx_buf_nb(param_2 & 0xff);
    r_ble_util_buf_set_rx_buf_size(param_1 & 0xffff);
    *(undefined1 *)(_p_lld_env + 0x101) = 1;
    _DAT_600312d0 = uVar7 * 0x14 + 0x1000 | _DAT_600312d0 & 0xffff0000 | 0x8000;
    (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
    uVar8 = 1;
    if (2 < _g_bt_plf_log_level) {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar6 + iVar5);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      ets_printf("RXBUF Update RXDESC: Current %04x[%d], RD %d; Jump %04x[%d], RD %d, NextPTR %04x\n"
                 ,uVar3 & 0x7fff,uVar4,uVar1 >> 0xf,iVar5 + 0x1000,uVar7,uVar2 >> 0xf,
                 *(ushort *)(iVar6 + iVar5) & 0x7fff);
      uVar8 = 1;
    }
  }
  else {
    uVar8 = 0;
    if (0 < _g_bt_plf_log_level) {
      ets_printf("RXBUF Update failed, SZ %d, NB %d!\n",param_1,param_2);
    }
  }
  return uVar8;
}

