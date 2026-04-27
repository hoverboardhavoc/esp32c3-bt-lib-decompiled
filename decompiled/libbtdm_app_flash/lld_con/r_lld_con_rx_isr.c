/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_rx_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_isr(uint param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_a1;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort *puVar13;
  int iVar14;
  uint uVar15;
  
  if (*(int *)(&lld_con_env + param_1 * 4) == 0) {
    r_assert_param(0,"lld_con.c",0xd6d);
    return;
  }
  iVar4 = r_rwip_time_get();
  iVar8 = param_1 * 4;
  iVar3 = *(int *)(&lld_con_env + iVar8);
  *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) & 0xfffb;
  puVar13 = (ushort *)(lld_con_fake_rx + iVar8);
  while (iVar5 = r_lld_rxdesc_check_hack(param_1), iVar5 != 0) {
    uVar15 = (uint)*(byte *)(_p_lld_env + 0xd8);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    iVar14 = uVar15 * 0x14;
    uVar7 = *(ushort *)(iVar14 + 2 + iVar6);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar1 = *(ushort *)(iVar14 + 4 + iVar6);
    iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
    uVar10 = (uint)(*(ushort *)(iVar14 + 6 + iVar6) >> 0xe);
    if ((uVar10 - 2 & 0xff) < 2) {
      if (uVar1 >> 8 == 0 && (uVar7 & 0x2f) == 0) {
        iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar2 = *(ushort *)(iVar14 + 10 + iVar6);
        if ((uVar2 & 0xf000) != 0) {
          r_assert_err(0,"lld_con.c",1000);
        }
        iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
        iVar11 = CONCAT22(uVar2,*(undefined2 *)(iVar14 + 8 + iVar6));
        iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
        uVar9 = iVar4 - iVar11 & 0xfffffff;
        if (uVar9 < 0x8000001) {
          uVar12 = 0x271;
        }
        else {
          uVar12 = iVar11 - iVar4 & 0xfffffff;
          uVar9 = 0xfffffd8f;
        }
        if (uVar10 == 2) {
          iVar11 = 0x2ff;
        }
        else {
          iVar11 = 0xfb;
        }
        if (((int)((extraout_a1 - (0x270 - (*(ushort *)(iVar14 + 0xc + iVar6) & 0x3ff))) +
                   uVar9 * uVar12 + (uint)_DAT_0001608e * 2) <= iVar11) ||
           ((((lld_con_fake_rx[iVar8 + 2] & 0x26) == 0 && (((*puVar13 ^ uVar1) & 0xff) == 0)) &&
            (*puVar13 >> 8 != 0)))) {
          *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) | 0x8000;
          lld_con_fake_rx[iVar8 + 2] = (char)uVar7;
          *puVar13 = uVar1;
        }
      }
      if (-1 < (short)*(ushort *)(iVar3 + 0x84)) {
        *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) & 0xf7ff;
      }
      if (((uVar7 & 1) == 0) && (-1 < *(short *)(iVar3 + 0x84))) {
        lld_con_fake_rx[iVar8 + 2] = (char)uVar7;
        *puVar13 = uVar1;
        r_ble_log_internal_x2(0x20c3010c,CONCAT22(uVar1,uVar1),uVar10 << 8 | param_1);
      }
    }
    r_ble_log_internal_x2(0x20c3010d,CONCAT22(uVar1,uVar7),uVar15 << 8 | param_1);
    if (((uVar7 & 1) == 0) && (r_lld_con_rx_sync_time_update(param_1,iVar3), (uVar7 & 8) == 0)) {
      *(undefined4 *)(iVar3 + 0x58) = *(undefined4 *)(iVar3 + 0x50);
      if ((uVar7 & 0x66) == 0) {
        if ((uVar7 & 0x10) == 0) {
          *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) | 0x4000;
          iVar6 = r_emi_get_mem_addr_by_offset(0x400);
          uVar7 = uVar1 >> 8;
          *(undefined2 *)(iVar3 + 0x98) = *(undefined2 *)(iVar6 + param_1 * 0x5a + 0x50);
          if ((uVar7 != 0) && ((uVar1 & 3) != 0)) {
            if ((4 < uVar7) && ((*(ushort *)(iVar3 + 0x84) & 0x20) != 0)) {
              uVar7 = uVar7 - 4;
            }
            iVar6 = r_lld_con_rx_llcp_check(param_1,iVar3,uVar7);
            if (iVar6 == 0) {
              iVar6 = r_emi_get_mem_addr_by_offset(0x1000);
              *(undefined2 *)(iVar14 + 0x12 + iVar6) = 0;
            }
          }
        }
        else {
          r_ble_log_internal_x1(0x80c3010e,uVar15 << 0x18 | param_1 << 0x10 | (uint)uVar7);
          *(ushort *)(iVar3 + 0x84) = *(ushort *)(iVar3 + 0x84) | 0x80;
          *(undefined1 *)(iVar3 + 0x8f) = 2;
        }
      }
    }
    else {
      iVar5 = 0;
    }
    r_lld_con_rx_channel_assess_hack(iVar3,iVar5);
    r_lld_rxdesc_free();
  }
  return;
}

