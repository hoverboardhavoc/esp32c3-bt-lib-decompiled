/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_frm_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_frm_rx_isr(uint param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  if ((_lld_scan_env == 0) || (*(int *)(_lld_scan_env + param_1 * 4) == 0)) {
    r_assert_err(0,"lld_scan.c",0x9c1);
    return;
  }
  iVar11 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar6 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar11 + 0x38));
    if (uVar6 == 0) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar11 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar7 + iVar11) < 0) {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar2 = *(ushort *)(iVar7 + iVar11);
        iVar7 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar11 + iVar7) = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
      }
      return;
    }
    uVar12 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar9 = uVar12 * 0x14;
    uVar3 = *(undefined2 *)(iVar9 + 0x12 + iVar7);
    if (*(ushort *)(iVar11 + 0x36) < 0x673) {
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar2 = *(ushort *)(iVar9 + 2 + iVar7);
      iVar13 = iVar9 + 4;
      iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar5 = *(ushort *)(iVar7 + iVar13) & 0xf;
      if (uVar5 < 7) {
        uVar10 = uVar6;
        if (*(char *)(_lld_scan_env + 0x17) != '\0') {
          r_lld_ext_scan_dynamic_pti_reset(iVar11);
        }
_L537:
        uVar6 = 0x128U >> uVar5 & 1;
      }
      else {
        iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar4 = *(ushort *)(iVar9 + 0x10 + iVar7);
        iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar10 = (uint)((uVar4 & 0x3f) < *(ushort *)(iVar7 + iVar13) >> 8);
        if (uVar5 < 9) goto _L537;
      }
      iVar7 = r_sdk_config_get_opts_ext();
      if (*(char *)(iVar7 + 0x18) == '\0') {
        uVar6 = (uint)(6 < uVar5) | uVar6 & 0xff;
      }
      if ((((uVar2 & 0x602d) == 0) && (uVar10 != 0)) && (uVar6 == 0)) {
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 8) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x40a1000a,
                     uVar5 << 0x10 | (uint)*(byte *)(iVar11 + 0x3d) << 0x18 | uVar12 << 8 | param_1)
          ;
        }
        uStack_44 = 0xff;
        *(undefined1 *)(iVar11 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar5) || ((0x128U >> uVar5 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x272);
        }
        if (uVar5 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_1,uVar5,uVar12,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep(param_1,uVar5,uVar12,&uStack_4c);
        iVar7 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar7 + 0x28) & 8) != 0) &&
           (iVar7 = r_sdk_config_get_opts_ext(), *(byte *)(iVar7 + 0x2c) < 2)) {
          iVar7 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar2 = *(ushort *)(iVar7 + iVar13);
          uVar8 = r_emi_get_mem_addr_by_offset(uVar3);
          r_ble_log_internal_hex(0x20a1000c,uVar2 >> 8,uVar8);
        }
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_1),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar11);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

