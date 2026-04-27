/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_eof_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_eof_isr(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined2 uVar5;
  bool bVar6;
  char cVar7;
  int *piVar8;
  int iVar9;
  undefined1 *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  char cVar16;
  undefined4 uStack_44;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined1 uStack_34;
  char acStack_31 [9];
  
  iVar15 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar15 == 0) {
    r_assert_err(0,0x10000,0x448);
    return;
  }
  bVar1 = *(byte *)(iVar15 + 0x55);
  iVar9 = (uint)bVar1 * 0x5a;
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar2 = *(ushort *)(iVar9 + 0x16 + iVar11);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar3 = *(ushort *)(iVar11 + iVar9 + 4);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar4 = *(ushort *)(iVar11 + iVar9 + 4);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uVar5 = *(undefined2 *)(iVar9 + 0xe + iVar11);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_44 = CONCAT22(uVar5,*(undefined2 *)(iVar9 + 0xc + iVar11));
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_38 = *(undefined2 *)(iVar9 + 0x22 + iVar11);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_36 = *(undefined2 *)(iVar9 + 0x24 + iVar11);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  uStack_34 = (undefined1)*(undefined2 *)(iVar9 + 0x26 + iVar11);
  r_co_nb_good_le_channels(&uStack_38);
  if (*(char *)(iVar15 + 100) == '\0') {
    uVar14 = *(uint *)(iVar15 + 4) * 0x271;
    iVar11 = (int)((ulonglong)*(uint *)(iVar15 + 4) * 0x271 >> 0x20);
    uVar12 = *(int *)(iVar15 + 8) + uVar14;
    bVar6 = uVar12 < uVar14;
  }
  else {
    uVar14 = *(uint *)(iVar15 + 0x44) * 0x271;
    uVar12 = (int)*(short *)(iVar15 + 0x48) + uVar14;
    bVar6 = uVar12 < uVar14;
    iVar11 = (int)((ulonglong)*(uint *)(iVar15 + 0x44) * 0x271 >> 0x20) +
             ((int)*(short *)(iVar15 + 0x48) >> 0x1f);
  }
  r_ble_log_internal_x4
            (0x40450003,uStack_44,((uint)bVar6 + iVar11) * -0x80000000 | uVar12 >> 1,
             *(undefined2 *)(iVar15 + 0x4a),
             (uint)*(byte *)(iVar15 + 0x55) | param_2 << 8 | (uVar2 & 0x3f) << 0x10 |
             ((uVar3 & 0xc) << 2 | uVar4 & 3) << 0x18);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  r_ble_log_internal_x1(0x4045015f,*(ushort *)(iVar11 + iVar9) & 0x1f | (uint)bVar1 << 0x10);
  r_sch_arb_remove(iVar15,1);
  iVar11 = r_emi_get_mem_addr_by_offset(0x400);
  iVar9 = iVar9 + 0x18;
  if ((*(ushort *)(iVar11 + iVar9) >> 10 & 1) != 0) {
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    uVar2 = *(ushort *)(iVar11 + iVar9);
    iVar11 = r_emi_get_mem_addr_by_offset(0x400);
    *(ushort *)(iVar9 + iVar11) = uVar2 & 0xfbff;
    if (*(char *)(iVar15 + 0x62) == '\x01') {
      r_lld_sync_trunc_ind(param_1);
    }
    *(undefined1 *)(iVar15 + 99) = 0;
  }
  r_lld_sync_process_pkt_rx(param_1);
  if (((*(char *)(iVar15 + 99) == '\x02') ||
      ((*(char *)(iVar15 + 100) == '\0' && (*(char *)(iVar15 + 99) == '\x01')))) &&
     (*(char *)(iVar15 + 0x62) == '\x01')) {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar15 + 99) = 0;
  }
  if (*(char *)(iVar15 + 0x5b) == '\x02') {
    piVar8 = (int *)(&lld_sync_env + param_1 * 4);
    if (*piVar8 != 0) {
      r_ble_log_internal_x1(0x40050154,(uint)*(ushort *)(*piVar8 + 0x4a) | param_1 << 0x10);
      puVar10 = (undefined1 *)r_ke_msg_alloc(0x205,0,0xff,2);
      *puVar10 = (char)param_1;
      puVar10[1] = 0;
      r_ke_msg_send();
      r_ke_free(*piVar8);
      *piVar8 = 0;
    }
    return;
  }
  iVar15 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_31[0] = '\0';
  uStack_44._3_1_ = (char)param_2;
  do {
    cVar7 = uStack_44._3_1_;
    bVar1 = DAT_00013065;
    cVar16 = co_sca2ppm;
    if (uStack_44._3_1_ != '\0') {
      if (0xff < (uint)*(byte *)(iVar15 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,0x10000,0x342);
      }
      cVar16 = bVar1 + *(char *)(iVar15 + 0x16);
    }
    *(char *)(iVar15 + 0x16) = cVar16;
    if (*(char *)(iVar15 + 99) == '\x01') {
      uVar12 = *(uint *)(iVar15 + 0x2c);
      bVar1 = *(byte *)(iVar15 + 0x31);
      iVar9 = (int)*(short *)(iVar15 + 0x28);
      uVar14 = *(uint *)(iVar15 + 0x24);
    }
    else {
      iVar9 = 1;
      if ((((*(char *)(iVar15 + 100) != '\0') && (*(char *)(iVar15 + 0x62) == '\0')) &&
          (*(ushort *)(iVar15 + 0x4c) != 0)) && (iVar9 = -1, cVar7 == '\0')) {
        iVar11 = *(ushort *)(iVar15 + 0x4c) + 1;
        iVar9 = iVar11 * 0x10000 >> 0x10;
        *(short *)(iVar15 + 0x4e) = (short)iVar11 + *(short *)(iVar15 + 0x4a);
      }
      *(short *)(iVar15 + 0x4a) = *(short *)(iVar15 + 0x4a) + (short)iVar9;
      *(uint *)(iVar15 + 0x44) =
           iVar9 * *(int *)(iVar15 + 0x40) + *(int *)(iVar15 + 0x44) & 0xfffffff;
      iVar9 = r_lld_read_clock();
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar15 + 0x44)) + iVar9 & 0xfffffff) < 0x8000001) {
        iVar9 = r_lld_read_clock();
        uVar12 = iVar9 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar15 + 0x44)) & 0xfffffff;
        if (uVar12 != 0) {
          uVar2 = *(ushort *)(iVar15 + 0x4a);
          uVar14 = *(uint *)(iVar15 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar15 + 0x4e) & 0xffff) < 0x7fff) {
            iVar9 = ((uVar14 - 1) + uVar12) / uVar14 << 0x10;
          }
          else {
            iVar9 = ((*(ushort *)(iVar15 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar15 + 100) = 0;
          }
          *(ushort *)(iVar15 + 0x4a) = uVar2 + (short)((uint)iVar9 >> 0x10);
          *(uint *)(iVar15 + 0x44) = (iVar9 >> 0x10) * uVar14 + *(int *)(iVar15 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(byte *)(iVar15 + 0x57) == 0) {
        uVar12 = *(int *)(iVar15 + 0x40) * 6;
      }
      else {
        uVar12 = *(uint *)(iVar15 + 0x34);
      }
      if (uVar12 < (*(int *)(iVar15 + 0x44) - *(int *)(iVar15 + 0x3c) & 0xfffffffU)) {
        r_ble_log_internal_x4
                  (0x6005015d,*(undefined4 *)(iVar15 + 0x40),
                   (uint)*(ushort *)(iVar15 + 0x4a) | param_1 << 0x10 |
                   (uint)*(byte *)(iVar15 + 0x57) << 0x18);
_L224:
        r_lld_sync_cleanup(param_1,8);
        return;
      }
      iVar9 = r_rwip_active_check();
      uVar12 = 0x14;
      if (iVar9 == 0) {
        uVar12 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar9 = (((uint)((*(int *)(iVar15 + 0x44) - *(int *)(iVar15 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar15 + 0x5a) * 2) + uVar12)) / 100 + 0x10
      ;
      uVar12 = iVar9 * 2;
      uVar14 = *(int *)(iVar15 + 0x44) - uVar12 / 0x271 & 0xfffffff;
      uVar13 = (uint)*(ushort *)(iVar15 + 0x48) + iVar9 * -2 + (uVar12 / 0x271) * 0x271;
      iVar9 = (int)(uVar13 * 0x10000) >> 0x10;
      if (iVar9 < 0) {
        uVar14 = uVar14 - 1 & 0xfffffff;
        iVar9 = (int)(((uVar13 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar15 + 0x57) == '\0') {
        iVar11 = 300;
        if (*(char *)(iVar15 + 0x56) == '\0') {
          iVar11 = 0x1e;
        }
        uVar12 = uVar12 + iVar11;
        if (((uint)(*(int *)(iVar15 + 0x40) * 0x271) >> 1) - 0x96 < uVar12 >> 1) {
          r_ble_log_internal_x3(0x4005015e,(uint)*(ushort *)(iVar15 + 0x4a) | param_1 << 0x10);
          goto _L224;
        }
      }
      bVar1 = *(byte *)(iVar15 + 0x58);
      *(undefined2 *)(iVar15 + 0x52) = 0;
    }
    *(uint *)(iVar15 + 4) = uVar14;
    uVar14 = (uint)_DAT_00013072;
    *(int *)(iVar15 + 8) = iVar9;
    uVar14 = uVar12 * 2 + uVar14 +
             (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) * 2;
    if (400000 < uVar14) {
      uVar14 = 400000;
    }
    *(uint *)(iVar15 + 0x10) = uVar14;
    r_lld_sync_insert_eco(param_1,(int)&uStack_44 + 3,uVar12,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

