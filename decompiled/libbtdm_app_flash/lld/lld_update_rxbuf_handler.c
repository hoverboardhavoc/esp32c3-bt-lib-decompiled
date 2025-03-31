/*
 * Last changed at upstream commit 2fd7ad255fceabdfba56882ce4523efdba2fc255
 * https://github.com/espressif/esp32c3-bt-lib/commit/2fd7ad255fceabdfba56882ce4523efdba2fc255
 * Upstream date: 2025-03-31 11:18:40 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(566c8e3)
 * Source: libbtdm_app_flash -> lld.o -> lld_update_rxbuf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_update_rxbuf_handler(void)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar3 = ((_DAT_600312d0 & 0x7fff) - 0x1000) / 0x14;
  for (uVar4 = uVar3; uVar4 != uVar3 + 10; uVar4 = uVar4 + 1) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar5 = ((int)uVar4 % 10) * 0x14;
    sVar2 = *(short *)(iVar6 + iVar5 + 0x12);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((-1 < *(short *)(iVar6 + iVar5)) && (sVar2 != 0)) {
      r_ble_util_buf_rx_free(sVar2,0);
    }
  }
  while (iVar5 = r_ble_util_buf_rx_alloc(), iVar5 != 0) {
    r_ble_util_buf_rx_free(0);
  }
  r_ble_util_data_rx_buf_reset();
  iVar6 = r_ble_util_buf_get_rx_buf_size();
  iVar5 = 3;
  if (sdk_cfg_priv_opts == '\0') {
    iVar5 = 0;
  }
  uVar4 = iVar5 + iVar6;
  if ((uVar4 & 0xfe00) != 0) {
    r_assert_err(0,"lld.c",0x286e);
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | uVar4 & 0xffff;
  uVar8 = uVar3;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n",uVar4);
  }
  for (; iVar5 = _p_lld_env, uVar8 != uVar3 + 10; uVar8 = uVar8 + 1) {
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar5 = ((int)uVar8 % 10) * 0x14;
    uVar1 = *(ushort *)(iVar6 + iVar5 + 2);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    *(ushort *)(iVar6 + iVar5 + 2) = uVar1 & 0x7fff | 0x8000;
    iVar6 = r_ble_util_buf_get_rx_buf_nb();
    if ((int)uVar8 < (int)(iVar6 + uVar3)) {
      iVar6 = r_ble_util_buf_rx_alloc();
      if (iVar6 == 0) {
        r_assert_param(uVar8,uVar3,"lld.c",0x75b);
      }
      else {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
        *(short *)(iVar7 + iVar5 + 0x12) = (short)iVar6;
        if (uVar8 != uVar3) {
          iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar1 = *(ushort *)(iVar6 + iVar5);
          iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
          *(ushort *)(iVar6 + iVar5) = uVar1 & 0x7fff;
        }
      }
      *(char *)(_p_lld_env + 0xd9) = (char)uVar8;
    }
    else {
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      *(undefined2 *)(iVar6 + iVar5 + 0x12) = 0;
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar1 = *(ushort *)(iVar6 + iVar5);
      iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
      *(ushort *)(iVar6 + iVar5) = uVar1 & 0x7fff | 0x8000;
    }
  }
  *(char *)(_p_lld_env + 0xd8) = (char)uVar3;
  *(undefined1 *)(iVar5 + 0x101) = 0;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar1 = *(ushort *)(iVar5 + uVar3 * 0x14);
  iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
  iVar5 = _r_osi_funcs_p;
  *(ushort *)(uVar3 * 0x14 + iVar6) = uVar1 & 0x7fff;
  (**(code **)(iVar5 + 0x18))(*(code **)(iVar5 + 0x18));
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update OK\n");
  }
  return 0;
}

