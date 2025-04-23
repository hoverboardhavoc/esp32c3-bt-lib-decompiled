/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld.o -> lld_update_rxbuf_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 lld_update_rxbuf_handler(void)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  uVar3 = ((_DAT_600312d0 & 0x7fff) - 0x1000) / 0x14;
  uVar4 = uVar3;
  do {
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar9 = ((int)uVar4 % 10) * 0x14;
    sVar1 = *(short *)(iVar5 + 0x12 + iVar9);
    iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
    if ((-1 < *(short *)(iVar5 + iVar9)) && (sVar1 != 0)) {
      r_ble_util_buf_rx_free(sVar1,0);
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != uVar3 + 10);
  while (iVar5 = r_ble_util_buf_rx_alloc(), iVar5 != 0) {
    r_ble_util_buf_rx_free(0);
  }
  r_ble_util_data_rx_buf_reset();
  iVar5 = r_ble_util_buf_get_rx_buf_size();
  uVar4 = (-(uint)(sdk_cfg_priv_opts == '\0') & 0xfffffffd) + 3 + iVar5;
  uVar8 = uVar4 & 0xffff;
  if (0x1ff < uVar8) {
    r_assert_err(0,"lld.c",0x286e);
  }
  _DAT_600312d4 = _DAT_600312d4 & 0xfffffe00 | uVar8;
  uVar8 = uVar3;
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RX MAX LENGTH %d\n",uVar4);
  }
  for (; iVar5 = _p_lld_env, uVar8 != uVar3 + 10; uVar8 = uVar8 + 1) {
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar5 = ((int)uVar8 % 10) * 0x14;
    uVar2 = *(ushort *)(iVar9 + iVar5 + 2);
    iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
    *(ushort *)(iVar9 + iVar5 + 2) = uVar2 | 0x8000;
    iVar9 = r_ble_util_buf_get_rx_buf_nb();
    if ((int)uVar8 < (int)(iVar9 + uVar3)) {
      iVar9 = r_ble_util_buf_rx_alloc();
      if (iVar9 == 0) {
        r_assert_param(uVar8,uVar3,"lld.c",0x75b);
      }
      else {
        iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
        *(short *)(iVar5 + 0x12 + iVar6) = (short)iVar9;
        if (uVar8 != uVar3) {
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar2 = *(ushort *)(iVar9 + iVar5);
          iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
          *(ushort *)(iVar9 + iVar5) = uVar2 & 0x7fff;
        }
      }
      *(char *)(_p_lld_env + 0xd9) = (char)uVar8;
    }
    else {
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      *(undefined2 *)(iVar5 + 0x12 + iVar9) = 0;
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar9 + iVar5);
      iVar9 = r_emi_get_mem_addr_by_offset(0x1000);
      *(ushort *)(iVar5 + iVar9) = uVar2 | 0x8000;
    }
  }
  *(char *)(_p_lld_env + 0xd8) = (char)uVar3;
  *(undefined1 *)(iVar5 + 0x101) = 0;
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  uVar2 = *(ushort *)(iVar5 + uVar3 * 0x14);
  iVar5 = r_emi_get_mem_addr_by_offset(0x1000);
  pcVar7 = *(code **)(_r_osi_funcs_p + 0x18);
  *(ushort *)(uVar3 * 0x14 + iVar5) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  (*pcVar7)(pcVar7);
  if (2 < _g_bt_plf_log_level) {
    ets_printf("RXBUF Update OK\n");
  }
  return 0;
}

