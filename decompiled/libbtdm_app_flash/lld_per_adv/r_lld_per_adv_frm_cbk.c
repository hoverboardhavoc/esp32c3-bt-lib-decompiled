/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_frm_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_frm_cbk(undefined4 param_1,uint param_2,uint param_3)

{
  byte bVar1;
  undefined1 uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  byte bVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  char cVar14;
  uint uVar15;
  int iVar16;
  
  if (param_3 == 2) {
    return;
  }
  if (param_3 < 3) {
    uVar12 = param_2 & 0xff;
    if (param_3 != 0) {
      param_3 = 1;
    }
    iVar16 = *(int *)(&lld_per_adv_env + uVar12 * 4);
    if (iVar16 != 0) {
      bVar1 = *(byte *)(iVar16 + 0x52);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400,param_1);
      iVar9 = (uint)bVar1 * 0x5a;
      uVar3 = *(ushort *)(iVar9 + 0x16 + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar4 = *(ushort *)(iVar10 + iVar9 + 4);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar5 = *(ushort *)(iVar10 + iVar9 + 4);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar6 = *(undefined2 *)(iVar9 + 0xe + iVar10);
      iVar10 = r_emi_get_mem_addr_by_offset(0x400);
      uVar15 = *(uint *)(iVar16 + 4) * 0x271;
      uVar13 = *(int *)(iVar16 + 8) + uVar15;
      r_ble_log_internal_x4
                (0x40440002,CONCAT22(uVar6,*(undefined2 *)(iVar9 + 0xc + iVar10)),
                 uVar13 >> 1 |
                 ((uint)(uVar13 < uVar15) + (int)((ulonglong)*(uint *)(iVar16 + 4) * 0x271 >> 0x20))
                 * -0x80000000,*(undefined2 *)(iVar16 + 0x4c),
                 (uint)*(byte *)(iVar16 + 0x52) | param_3 << 8 | (uVar3 & 0x3f) << 0x10 |
                 ((uVar4 & 0xc) << 2 | uVar5 & 3) << 0x18);
    }
    iVar9 = r_emi_get_mem_addr_by_offset(0x400);
    r_ble_log_internal_x1(0x4044012d,uVar12 << 0x10 | *(ushort *)(uVar12 * 0x5a + iVar9) & 0x1f);
    if (periodic_adv_data_need_to_set[uVar12] != '\0') {
      *(undefined4 *)(iVar16 + 0x24) = 0;
      r_lld_per_adv_data_set(uVar12,0,0,1,1);
      periodic_adv_data_need_to_set[uVar12] = '\0';
    }
    iVar16 = *(int *)(&lld_per_adv_env + uVar12 * 4);
    if (iVar16 == 0) {
      r_assert_err(0,0x10000,0x459);
      return;
    }
    r_sch_arb_remove(iVar16,1);
    if (*(char *)(iVar16 + 0x53) != '\x02') {
      bVar1 = *(byte *)(iVar16 + 0x52);
      if (*(short *)(iVar16 + 0x24) != 0) {
        r_lld_per_adv_data_set(uVar12,*(undefined1 *)(iVar16 + 0x26),1,1);
        *(undefined2 *)(iVar16 + 0x24) = 0;
      }
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      iVar9 = ((uint)bVar1 * 9 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar10 + iVar9);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      *(ushort *)(iVar10 + iVar9) = (ushort)(((uint)uVar3 << 0x11) >> 0x11);
      iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
      if ((*(ushort *)(iVar9 + 6 + iVar10) >> 0xc & 1) != 0) {
        bVar1 = *(byte *)(iVar16 + 0x52);
        uVar12 = r_lld_ch_idx_get_hack();
        *(char *)(iVar16 + 0x57) = (char)uVar12;
        if ((uVar12 & 0xffffffc0) != 0) {
          r_assert_err(0,0x10000,0x2ea);
        }
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        uVar3 = *(ushort *)(iVar10 + iVar9 + 8);
        iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
        *(ushort *)(iVar10 + iVar9 + 8) = uVar3 & 0xffc0 | (ushort)uVar12;
        uVar12 = (uint)*(byte *)(iVar16 + 0x57) << 10;
        if ((uVar12 & 0x30000) != 0) {
          r_assert_err(0,0x10000,0x635);
        }
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        iVar10 = (uint)bVar1 * 0x5a + 0x26;
        uVar3 = *(ushort *)(iVar9 + iVar10);
        iVar9 = r_emi_get_mem_addr_by_offset(0x400);
        *(ushort *)(iVar9 + iVar10) = uVar3 & 0x3ff | (ushort)uVar12;
        uVar12 = 0;
        while( true ) {
          bVar1 = *(byte *)(iVar16 + 0x52);
          uVar12 = uVar12 + 1 & 0xff;
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          iVar9 = ((uint)bVar1 * 9 + uVar12 & 0xff) * 0xe;
          uVar3 = *(ushort *)(iVar10 + iVar9);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar10 + iVar9) = uVar3 & 0x7fff;
          if (uVar12 == *(byte *)(iVar16 + 0x58) - 1) break;
          bVar1 = *(byte *)(iVar16 + 0x57);
          if ((bVar1 & 0xc0) != 0) {
            r_assert_err(0,0x10000,0x2ea);
          }
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          uVar3 = *(ushort *)(iVar10 + iVar9 + 8);
          iVar10 = r_emi_get_mem_addr_by_offset(0x1400);
          *(ushort *)(iVar10 + iVar9 + 8) = uVar3 & 0xffc0 | (ushort)bVar1;
        }
      }
      bVar7 = DAT_0001301b;
      cVar14 = DAT_0001301a;
      if (param_3 != 0) {
        cVar14 = *(char *)(iVar16 + 0x16) + DAT_0001301b;
      }
      *(char *)(iVar16 + 0x16) = cVar14;
      bVar1 = *(byte *)(iVar16 + 0x52);
      *(ushort *)(iVar16 + 0x14) = bVar7 & 0xf | 0x2000;
r_lld_per_adv_sched_hack:
      iVar16 = *(int *)(&lld_per_adv_env + (uint)bVar1 * 4);
      *(uint *)(iVar16 + 4) = *(int *)(iVar16 + 4) + *(int *)(iVar16 + 0x40) & 0xfffffff;
      *(short *)(iVar16 + 0x4c) = *(short *)(iVar16 + 0x4c) + 1;
      iVar9 = r_lld_read_clock();
      while ((iVar9 - *(int *)(iVar16 + 4) & 0xfffffffU) < 0x7ffffff) {
        *(uint *)(iVar16 + 4) = *(int *)(iVar16 + 4) + *(int *)(iVar16 + 0x40) & 0xfffffff;
        *(short *)(iVar16 + 0x4c) = *(short *)(iVar16 + 0x4c) + 1;
      }
      uVar12 = 0;
      do {
        iVar10 = r_sch_arb_insert(iVar16);
        if (iVar10 == 0) {
          iVar10 = 1;
          goto _L4;
        }
        uVar12 = uVar12 + 1 & 0xff;
        *(byte *)(iVar16 + 0x16) = *(char *)(iVar16 + 0x16) + DAT_0001301b;
        *(uint *)(iVar16 + 4) = *(int *)(iVar16 + 4) + *(int *)(iVar16 + 0x40) & 0xfffffff;
        *(short *)(iVar16 + 0x4c) = *(short *)(iVar16 + 0x4c) + 1;
      } while (uVar12 != 0xf);
      iVar10 = 0;
_L4:
      r_ble_log_internal_x1
                (0x4044012c,
                 (uint)*(byte *)(iVar16 + 0x53) << 0x18 | (uint)bVar1 | iVar10 << 8 | uVar12 << 0x10
                );
      if (iVar10 == 0) {
        r_assert_param(*(undefined4 *)(iVar16 + 4),iVar9,0x10000,0x13f);
        return;
      }
      *(undefined1 *)(iVar16 + 0x53) = 0;
      return;
    }
    puVar11 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar2 = *(undefined1 *)(iVar16 + 0x52);
    puVar11[1] = 0;
    *puVar11 = uVar2;
    r_ke_msg_send();
  }
  else {
    if (param_3 != 4) {
      r_assert_param(param_3,0x10000,0x4af);
      return;
    }
    iVar16 = *(int *)(&lld_per_adv_env + (param_2 & 0xff) * 4);
    if (iVar16 == 0) {
      r_assert_err(0,0x10000,0x48e);
      return;
    }
    r_ble_log_internal_x1
              (0x40440134,
               (uint)*(byte *)(iVar16 + 0x53) << 8 | (uint)*(byte *)(iVar16 + 0x16) << 0x10 |
               param_2 & 0xff);
    if (1 < (byte)(*(char *)(iVar16 + 0x53) - 1U)) {
      r_assert_err(0,0x10000,0x472);
    }
    r_sch_arb_remove(iVar16,1);
    if (*(char *)(iVar16 + 0x53) != '\x02') {
      bVar1 = *(byte *)(iVar16 + 0x52);
      *(char *)(iVar16 + 0x16) = *(char *)(iVar16 + 0x16) + rwip_priority;
      goto r_lld_per_adv_sched_hack;
    }
    puVar11 = (undefined1 *)r_ke_msg_alloc(0x208,0,0xff,2);
    uVar2 = *(undefined1 *)(iVar16 + 0x52);
    puVar11[1] = 0;
    *puVar11 = uVar2;
    r_ke_msg_send();
  }
  param_2 = param_2 & 0xff;
  piVar8 = (int *)(&lld_per_adv_env + param_2 * 4);
  if (*piVar8 == 0) {
    r_ble_log_internal_x1(0x80040130,param_2);
    return;
  }
  r_ble_log_internal_x1(0x4004012f,param_2 << 0x10 | (uint)*(ushort *)(*piVar8 + 0x4c));
  r_ke_free(*piVar8);
  *piVar8 = 0;
  return;
}

