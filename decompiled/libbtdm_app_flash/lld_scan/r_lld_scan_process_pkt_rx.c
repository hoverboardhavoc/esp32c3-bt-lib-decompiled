/*
 * Last changed at upstream commit b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * https://github.com/espressif/esp32c3-bt-lib/commit/b09bf658a78c1c234d5ba7b3174f0dca7dd80c6b
 * Upstream date: 2025-04-28 11:55:39 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> lld_scan.o -> r_lld_scan_process_pkt_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_scan_process_pkt_rx(uint param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  
  iVar13 = *(int *)(param_1 * 4 + _lld_scan_env);
  bVar1 = *(byte *)(_lld_scan_env + 0xd);
  do {
    uVar7 = r_lld_rxdesc_check_hack(*(undefined1 *)(iVar13 + 0x38));
    if (uVar7 == 0) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar13 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      if (*(short *)(iVar8 + iVar13) < 0) {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar8 + iVar13);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar13 + iVar8) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      }
      return;
    }
    uVar14 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar11 = uVar14 * 0x14;
    uVar4 = *(undefined2 *)(iVar11 + 0x12 + iVar8);
    if (*(ushort *)(iVar13 + 0x36) < 0x673) {
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar3 = *(ushort *)(iVar11 + 2 + iVar8);
      iVar15 = iVar11 + 4;
      iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
      uVar6 = *(ushort *)(iVar8 + iVar15) & 0xf;
      if (uVar6 < 7) {
        bVar2 = *(byte *)(_lld_scan_env + 0x17);
        uVar12 = uVar7;
        if (bVar2 != 0) {
          r_lld_ext_scan_dynamic_pti_reset(iVar13);
          uVar12 = (uint)bVar2;
        }
_L559:
        uVar10 = 0x128U >> uVar6 & 1;
      }
      else {
        iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar5 = *(ushort *)(iVar11 + 0x10 + iVar8);
        iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar12 = (uint)((uVar5 & 0x3f) < *(ushort *)(iVar8 + iVar15) >> 8);
        uVar10 = uVar7;
        if (uVar6 < 9) goto _L559;
      }
      iVar8 = r_sdk_config_get_opts_ext();
      if ((*(char *)(iVar8 + 0x18) == '\0') && (6 < uVar6)) {
        uVar10 = uVar7;
      }
      if ((((uVar3 & 0x602d) == 0) && (uVar12 != 0)) && (uVar10 == 0)) {
        iVar8 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar8 + 0x28) & 8) != 0) &&
           (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 3)) {
          r_ble_log_internal_x1
                    (0x40a1000a,
                     uVar6 << 0x10 | uVar14 << 8 | param_1 | (uint)*(byte *)(iVar13 + 0x3d) << 0x18)
          ;
        }
        uStack_44 = 0xff;
        *(undefined1 *)(iVar13 + 0x43) = 1;
        uStack_4c = 0;
        uStack_48 = 0;
        if ((8 < uVar6) || ((0x128U >> uVar6 & 1) != 0)) {
          r_assert_err(0,"lld_scan.c",0x272);
        }
        if (uVar6 < 7) {
          r_lld_scan_process_pkt_rx_legacy_adv();
        }
        else {
          r_lld_scan_process_pkt_rx_ext_adv(param_1,uVar6,uVar14,&uStack_4c);
        }
        r_lld_scan_process_pkt_rx_adv_rep(param_1,uVar6,uVar14,&uStack_4c);
        iVar8 = r_sdk_config_get_opts_ext();
        if (((*(uint *)(iVar8 + 0x28) & 8) != 0) &&
           (iVar8 = r_sdk_config_get_opts_ext(), *(byte *)(iVar8 + 0x2c) < 2)) {
          iVar8 = r_emi_get_mem_addr_by_offset(0x1000);
          uVar3 = *(ushort *)(iVar8 + iVar15);
          uVar9 = r_emi_get_mem_addr_by_offset(uVar4);
          r_ble_log_internal_hex(0x20a1000c,uVar3 >> 8,uVar9);
        }
      }
      else if (((_DAT_60031048 & 8) != 0) &&
              (r_lld_continue_scan_rx_isr_end_process(param_1),
              *(char *)(_lld_scan_env + 0x17) != '\0')) {
        r_lld_ext_scan_dynamic_pti_reset(iVar13);
      }
    }
    r_lld_rxdesc_free();
  } while( true );
}

