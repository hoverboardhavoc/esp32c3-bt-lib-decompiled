/*
 * Last changed at upstream commit 7e73ebf92e5aa995065351043c13d2ac0f00772e
 * https://github.com/espressif/esp32c3-bt-lib/commit/7e73ebf92e5aa995065351043c13d2ac0f00772e
 * Upstream date: 2026-05-19 17:43:45 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(bc853c5)
 * Source: libbtdm_app_flash -> lld_con.o -> r_lld_con_evt_start_cbk_eco
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_evt_start_cbk_eco(int param_1)

{
  byte bVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  short sVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  byte *pbVar10;
  undefined1 *puVar11;
  undefined2 *puVar12;
  undefined4 uVar13;
  ushort uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  
  if (param_1 == 0) goto _L558;
  if (*(short *)(param_1 + 0x84) < 0) {
    uVar15 = (uint)*(byte *)(param_1 + 0x8e);
    iVar16 = uVar15 * 4;
    if (-1 < (char)lld_con_fake_rx[iVar16 + 2]) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      iVar17 = uVar15 * 0x5a + 0x18;
      uVar14 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar17) =
           (ushort)((~((int)(uint)uVar14 >> 0xd) & 1U) << 0xd) | uVar4 & 0xdfff;
      bVar1 = *(byte *)(param_1 + 0x8e);
      bVar2 = *(byte *)(param_1 + 0x90);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(uVar15 * 0x5a + 0x1c + iVar9) =
           ((ushort)bVar1 * 9 + (ushort)bVar2 & 0xff) * 0xe + 0x1400;
    }
    if ((lld_con_fake_rx[iVar16 + 2] & 0x40) == 0) {
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      iVar17 = uVar15 * 0x5a + 0x18;
      uVar14 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar9 + iVar17);
      iVar9 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar9 + iVar17) =
           (ushort)((~((int)(uint)uVar14 >> 0xc) & 1U) << 0xc) | uVar4 & 0xefff;
    }
    if ((*(ushort *)(param_1 + 0x84) >> 0xb & 1) == 0) {
      if (-1 < (char)lld_con_fake_rx[iVar16 + 2]) {
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        iVar17 = uVar15 * 0x5a + 0x18;
        uVar14 = *(ushort *)(iVar9 + iVar17);
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar9 + iVar17) = uVar14 & 0xbfff | 0x4000;
      }
    }
    else {
      iVar17 = r_emi_get_mem_addr_by_offset(0x400);
      iVar9 = uVar15 * 0x5a + 0x18;
      uVar14 = *(ushort *)(iVar17 + iVar9);
      iVar17 = r_emi_get_mem_addr_by_offset(0x400);
      *(ushort *)(iVar17 + iVar9) = uVar14 & 0xbfff;
    }
    bVar1 = lld_con_fake_rx[iVar16 + 2];
    r_ble_log_internal_x4
              (0x40c30103,bVar1 >> 7,bVar1 >> 6 & 1,
               (int)(uint)*(ushort *)(param_1 + 0x84) >> 0xb & 1,
               CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x8e)));
    *(ushort *)(param_1 + 0x84) = *(ushort *)(param_1 + 0x84) & 0x77ff;
  }
  bVar1 = *(byte *)(param_1 + 0x8e);
  uVar13 = *(undefined4 *)(param_1 + 4);
  iVar16 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x3
            (0x40430104,uVar13,
             *(int *)(param_1 + 8) << 0x10 | *(ushort *)((uint)bVar1 * 0x5a + iVar16) & 0x1f);
  iVar16 = (*(byte *)(param_1 + 0x8e) + 0x18) * 2;
  if (((&DAT_00015809)[iVar16] != '\0') && (*(char *)(param_1 + 0x46) == (&DAT_00015809)[iVar16])) {
    uVar15 = (uint)*(ushort *)(param_1 + 0x7c) + (uint)*(ushort *)(param_1 + 0x7e) & 0xffff;
    bVar1 = (&DAT_00015808)[iVar16];
    if (((uVar15 - *(ushort *)(param_1 + 0x44)) + 1 & 0xffff) < 0x7fff) {
      iVar9 = (uint)bVar1 * 0xe;
      iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
      if (-1 < *(short *)(iVar17 + iVar9)) {
        iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
        sVar5 = *(short *)(iVar9 + 4 + iVar17);
        iVar17 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar14 = (ushort)(byte)(&DAT_00015809)[iVar16];
        uVar6 = *(ushort *)(iVar9 + 2 + iVar17) & 3;
        if (uVar14 == 1) {
          uVar14 = 10;
_L587:
          uVar18 = 0;
        }
        else if (uVar14 == 2) {
          uVar14 = 6;
          uVar18 = 1;
        }
        else {
          uVar18 = 0x18;
          if (uVar14 != 3) {
            r_assert_param(*(undefined1 *)(param_1 + 0x8e),0,"lld_con.c",0x646);
            uVar14 = 0;
            goto _L587;
          }
        }
        if (((sVar5 == 0) || (uVar6 != 3)) ||
           (pbVar10 = (byte *)r_emi_get_mem_addr_by_offset(sVar5), *pbVar10 != uVar18)) {
          if (0 < _g_bt_plf_log_level) {
            puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar5);
            uVar3 = *puVar11;
            puVar12 = (undefined2 *)r_emi_get_mem_addr_by_offset(sVar5 + uVar14);
            ets_printf("llcp check: %u %u %u %u %u\n",uVar15,uVar3,*puVar12,
                       *(undefined1 *)(param_1 + 0x46),*(undefined2 *)(param_1 + 0x44));
          }
          bVar1 = *(byte *)(param_1 + 0x8e);
          r_lld_con_llcp_ind_info_clear((uint)bVar1);
          uVar7 = (uint)*(ushort *)(param_1 + 0x44);
          uVar6 = (uint)*(byte *)(param_1 + 0x46) << 0x18 | (uint)bVar1 | uVar6 << 8;
          uVar13 = 0x80a30106;
        }
        else {
          uVar7 = *(ushort *)(param_1 + 0x72) + 9 + uVar15;
          iVar16 = uVar7 * 0x10000;
          puVar11 = (undefined1 *)r_emi_get_mem_addr_by_offset(sVar5 + uVar14);
          uVar7 = uVar7 & 0xffff;
          *puVar11 = (char)((uint)iVar16 >> 0x10);
          puVar11[1] = (char)(uVar7 >> 8);
          uVar6 = (uint)CONCAT11(bVar1,*(undefined1 *)(param_1 + 0x8e));
          *(short *)(param_1 + 0x44) = (short)((uint)iVar16 >> 0x10);
          uVar13 = 0x40a30105;
        }
        r_ble_log_internal_x2(uVar13,uVar7 << 0x10 | uVar15,uVar6 | uVar18 << 0x10);
      }
    }
  }
  if (((*(char *)(param_1 + 0x46) != '\0') &&
      ((ushort)(*(short *)(param_1 + 0x7c) - *(short *)(param_1 + 0x44)) < 0x7fff)) &&
     (*(char *)(param_1 + 0x46) == '\x03')) {
    uVar15 = (uint)*(byte *)(param_1 + 0x8e);
    if ((byte)(*(char *)(param_1 + 0x35) - 2U) < 2) {
      if (0xb < uVar15) {
        r_assert_err(0,"lld_con.c",0x29bb);
      }
      puVar8 = (uint *)((uVar15 + 0x1800c4cb) * 4);
      *puVar8 = *puVar8 & 0xfffffff0 | 0xe;
      if (0xb < uVar15) {
        r_assert_err(0,"lld_con.c",0x295a);
      }
      uVar15 = *puVar8 & 0xdfffffff | 0x20000000;
    }
    else {
      if (0xb < uVar15) {
        r_assert_err(0,"lld_con.c",0x29bb);
      }
      puVar8 = (uint *)((uVar15 + 0x1800c4cb) * 4);
      *puVar8 = *puVar8 & 0xfffffff0;
      if (0xb < uVar15) {
        r_assert_err(0,"lld_con.c",0x295a);
      }
      uVar15 = *puVar8 & 0xdfffffff;
    }
    *puVar8 = uVar15;
  }
_L558:
  r_lld_con_evt_start_cbk(param_1);
  iVar16 = r_sdk_config_get_opts_ext();
  if (*(char *)(iVar16 + 0x19) == '\x02') {
    r_lld_cca_con_evt_start_handle(param_1);
  }
  if (con_evt_func_cb == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00010014. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*con_evt_func_cb)(*(undefined1 *)(param_1 + 0x8e),1);
  return;
}

