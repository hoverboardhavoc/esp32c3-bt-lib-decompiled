/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_frm_skip_isr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_frm_skip_isr(int param_1)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  char cVar14;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar6 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar6 == 0) {
    r_assert_err(0,0x10000,0x48c);
    return;
  }
  r_ble_log_internal_x2
            (0x40450160,
             (uint)*(ushort *)(iVar6 + 0x4a) | param_1 << 0x10 | (uint)*(byte *)(iVar6 + 99) << 0x18
             ,*(undefined1 *)(iVar6 + 0x5b));
  r_sch_arb_remove(iVar6,1);
  if (*(char *)(iVar6 + 99) == '\x01') {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar6 + 99) = 0;
  }
  bVar2 = *(byte *)(iVar6 + 0x55);
  uVar8 = (uint)bVar2;
  if (*(char *)(iVar6 + 0x5b) == '\x02') {
    piVar5 = (int *)(&lld_sync_env + uVar8 * 4);
    if (*piVar5 != 0) {
      r_ble_log_internal_x1(0x40050154,(uint)CONCAT12(bVar2,*(undefined2 *)(*piVar5 + 0x4a)));
      pbVar7 = (byte *)r_ke_msg_alloc(0x205,0,0xff,2);
      *pbVar7 = bVar2;
      pbVar7[1] = 0;
      r_ke_msg_send();
      r_ke_free(*piVar5);
      *piVar5 = 0;
    }
    return;
  }
  iVar6 = *(int *)(&lld_sync_env + uVar8 * 4);
  acStack_41[0] = '\x01';
  acStack_31[0] = '\0';
  do {
    cVar4 = acStack_41[0];
    bVar1 = DAT_00013065;
    cVar14 = co_sca2ppm;
    if (acStack_41[0] != '\0') {
      if (0xff < (uint)*(byte *)(iVar6 + 0x16) + (uint)DAT_00013065) {
        r_assert_err(0,0x10000,0x342);
      }
      cVar14 = bVar1 + *(char *)(iVar6 + 0x16);
    }
    *(char *)(iVar6 + 0x16) = cVar14;
    if (*(char *)(iVar6 + 99) == '\x01') {
      uVar9 = *(uint *)(iVar6 + 0x2c);
      bVar1 = *(byte *)(iVar6 + 0x31);
      iVar11 = (int)*(short *)(iVar6 + 0x28);
      uVar10 = *(uint *)(iVar6 + 0x24);
    }
    else {
      iVar11 = 1;
      if ((((*(char *)(iVar6 + 100) != '\0') && (*(char *)(iVar6 + 0x62) == '\0')) &&
          (*(ushort *)(iVar6 + 0x4c) != 0)) && (iVar11 = -1, cVar4 == '\0')) {
        iVar12 = *(ushort *)(iVar6 + 0x4c) + 1;
        iVar11 = iVar12 * 0x10000 >> 0x10;
        *(short *)(iVar6 + 0x4e) = (short)iVar12 + *(short *)(iVar6 + 0x4a);
      }
      *(short *)(iVar6 + 0x4a) = *(short *)(iVar6 + 0x4a) + (short)iVar11;
      *(uint *)(iVar6 + 0x44) = iVar11 * *(int *)(iVar6 + 0x40) + *(int *)(iVar6 + 0x44) & 0xfffffff
      ;
      iVar11 = r_lld_read_clock();
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar6 + 0x44)) + iVar11 & 0xfffffff) < 0x8000001) {
        iVar11 = r_lld_read_clock();
        uVar9 = iVar11 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar6 + 0x44)) & 0xfffffff;
        if (uVar9 != 0) {
          uVar3 = *(ushort *)(iVar6 + 0x4a);
          uVar10 = *(uint *)(iVar6 + 0x40);
          if (((uint)uVar3 - (uint)*(ushort *)(iVar6 + 0x4e) & 0xffff) < 0x7fff) {
            iVar11 = ((uVar10 - 1) + uVar9) / uVar10 << 0x10;
          }
          else {
            iVar11 = ((*(ushort *)(iVar6 + 0x4e) + 1) - (uint)uVar3) * 0x10000;
            *(undefined1 *)(iVar6 + 100) = 0;
          }
          *(ushort *)(iVar6 + 0x4a) = uVar3 + (short)((uint)iVar11 >> 0x10);
          *(uint *)(iVar6 + 0x44) = (iVar11 >> 0x10) * uVar10 + *(int *)(iVar6 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar6 + 0x57) == '\0') {
        uVar9 = *(int *)(iVar6 + 0x40) * 6;
      }
      else {
        uVar9 = *(uint *)(iVar6 + 0x34);
      }
      if (uVar9 < (*(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x3c) & 0xfffffffU)) {
        r_ble_log_internal_x4
                  (0x6005015d,*(undefined4 *)(iVar6 + 0x40),
                   CONCAT13(*(char *)(iVar6 + 0x57),CONCAT12(bVar2,*(undefined2 *)(iVar6 + 0x4a))));
_L224:
        r_lld_sync_cleanup(uVar8,8);
        return;
      }
      iVar11 = r_rwip_active_check();
      uVar9 = 0x14;
      if (iVar11 == 0) {
        uVar9 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar11 = (((uint)((*(int *)(iVar6 + 0x44) - *(int *)(iVar6 + 0x38)) * 0x10) >> 8) *
               (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar6 + 0x5a) * 2) + uVar9)) / 100 + 0x10;
      uVar9 = iVar11 * 2;
      uVar10 = *(int *)(iVar6 + 0x44) - uVar9 / 0x271 & 0xfffffff;
      uVar13 = (uint)*(ushort *)(iVar6 + 0x48) + iVar11 * -2 + (uVar9 / 0x271) * 0x271;
      iVar11 = (int)(uVar13 * 0x10000) >> 0x10;
      if (iVar11 < 0) {
        uVar10 = uVar10 - 1 & 0xfffffff;
        iVar11 = (int)(((uVar13 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar6 + 0x57) == '\0') {
        iVar12 = 300;
        if (*(char *)(iVar6 + 0x56) == '\0') {
          iVar12 = 0x1e;
        }
        uVar9 = uVar9 + iVar12;
        if (((uint)(*(int *)(iVar6 + 0x40) * 0x271) >> 1) - 0x96 < uVar9 >> 1) {
          r_ble_log_internal_x3(0x4005015e,(uint)CONCAT12(bVar2,*(undefined2 *)(iVar6 + 0x4a)));
          goto _L224;
        }
      }
      bVar1 = *(byte *)(iVar6 + 0x58);
      *(undefined2 *)(iVar6 + 0x52) = 0;
    }
    *(uint *)(iVar6 + 4) = uVar10;
    uVar10 = (uint)_DAT_00013072;
    *(int *)(iVar6 + 8) = iVar11;
    uVar10 = uVar9 * 2 + uVar10 + (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) * 2
    ;
    if (400000 < uVar10) {
      uVar10 = 400000;
    }
    *(uint *)(iVar6 + 0x10) = uVar10;
    r_lld_sync_insert_eco(uVar8,acStack_41,uVar9,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

