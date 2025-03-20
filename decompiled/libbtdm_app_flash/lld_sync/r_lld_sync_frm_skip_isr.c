/*
 * Last changed at upstream commit aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * https://github.com/espressif/esp32c3-bt-lib/commit/aaf54a5f7e122db70b4a7ff02d2617858d43f649
 * Upstream date: 2025-03-20 20:31:24 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(d74042a8)
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
  ushort uVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short sVar11;
  uint uVar12;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar4 = *(int *)(&lld_sync_env + param_1 * 4);
  if (iVar4 == 0) {
    r_assert_err(0,"lld_sync.c",1099);
    return;
  }
  r_sch_arb_remove(iVar4,1);
  if (*(char *)(iVar4 + 99) == '\x01') {
    r_lld_sync_trunc_ind(param_1);
    *(undefined1 *)(iVar4 + 99) = 0;
  }
  bVar1 = *(byte *)(iVar4 + 0x55);
  uVar6 = (uint)bVar1;
  if (*(char *)(iVar4 + 0x5b) == '\x02') {
    piVar3 = (int *)(&lld_sync_env + uVar6 * 4);
    if (*piVar3 != 0) {
      pbVar5 = (byte *)r_ke_msg_alloc(0x205,0,0xff,2);
      *pbVar5 = bVar1;
      pbVar5[1] = 0;
      r_ke_msg_send();
      r_ke_free(*piVar3);
      *piVar3 = 0;
    }
    return;
  }
  iVar4 = *(int *)(&lld_sync_env + uVar6 * 4);
  acStack_41[0] = '\x01';
  acStack_31[0] = '\0';
  do {
    bVar1 = DAT_00012055;
    if (acStack_41[0] == '\0') {
      *(undefined1 *)(iVar4 + 0x16) = co_sca2ppm;
    }
    else {
      if (0xff < (uint)*(byte *)(iVar4 + 0x16) + (uint)DAT_00012055) {
        r_assert_err(0,"lld_sync.c",0x329);
      }
      *(byte *)(iVar4 + 0x16) = bVar1 + *(char *)(iVar4 + 0x16);
    }
    if (*(char *)(iVar4 + 99) == '\x01') {
      uVar8 = *(uint *)(iVar4 + 0x2c);
      bVar1 = *(byte *)(iVar4 + 0x31);
      iVar7 = (int)*(short *)(iVar4 + 0x28);
      uVar12 = *(uint *)(iVar4 + 0x24);
    }
    else {
      iVar7 = 1;
      if ((((*(char *)(iVar4 + 100) != '\0') && (*(char *)(iVar4 + 0x62) == '\0')) &&
          (*(short *)(iVar4 + 0x4c) != 0)) && (iVar7 = -1, acStack_41[0] == '\0')) {
        sVar11 = *(short *)(iVar4 + 0x4c) + 1;
        iVar7 = (int)sVar11;
        *(short *)(iVar4 + 0x4e) = sVar11 + *(short *)(iVar4 + 0x4a);
      }
      *(short *)(iVar4 + 0x4a) = *(short *)(iVar4 + 0x4a) + (short)iVar7;
      *(uint *)(iVar4 + 0x44) = iVar7 * *(int *)(iVar4 + 0x40) + *(int *)(iVar4 + 0x44) & 0xfffffff;
      iVar7 = r_lld_read_clock();
      if ((iVar7 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) & 0xfffffff) < 0x8000001) {
        iVar7 = r_lld_read_clock();
        uVar8 = iVar7 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar4 + 0x44)) & 0xfffffff;
        if (uVar8 != 0) {
          uVar2 = *(ushort *)(iVar4 + 0x4a);
          uVar9 = *(uint *)(iVar4 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar4 + 0x4e) & 0xffff) < 0x7fff) {
            iVar7 = ((uVar9 - 1) + uVar8) / uVar9 << 0x10;
          }
          else {
            iVar7 = ((*(ushort *)(iVar4 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar4 + 100) = 0;
          }
          *(ushort *)(iVar4 + 0x4a) = (short)((uint)iVar7 >> 0x10) + uVar2;
          *(uint *)(iVar4 + 0x44) = (iVar7 >> 0x10) * uVar9 + *(int *)(iVar4 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        uVar8 = *(int *)(iVar4 + 0x40) * 6;
      }
      else {
        uVar8 = *(uint *)(iVar4 + 0x34);
      }
      if (uVar8 < (*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x3c) & 0xfffffffU)) {
_L211:
        r_lld_sync_cleanup(uVar6,8);
        return;
      }
      iVar7 = r_rwip_active_check();
      uVar8 = 0x14;
      if (iVar7 == 0) {
        uVar8 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar7 = (((uint)((*(int *)(iVar4 + 0x44) - *(int *)(iVar4 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar4 + 0x5a) * 2) + uVar8)) / 100 + 0x10;
      uVar8 = iVar7 * 2;
      uVar12 = *(int *)(iVar4 + 0x44) - uVar8 / 0x271 & 0xfffffff;
      uVar9 = (uint)*(ushort *)(iVar4 + 0x48) + iVar7 * -2 + (uVar8 / 0x271) * 0x271;
      iVar7 = (int)(short)uVar9;
      if (iVar7 < 0) {
        uVar12 = uVar12 - 1 & 0xfffffff;
        iVar7 = (int)(((uVar9 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar4 + 0x57) == '\0') {
        iVar10 = 300;
        if (*(char *)(iVar4 + 0x56) == '\0') {
          iVar10 = 0x1e;
        }
        uVar8 = uVar8 + iVar10;
        if (((uint)(*(int *)(iVar4 + 0x40) * 0x271) >> 1) - 0x96 < uVar8 >> 1) goto _L211;
      }
      *(undefined2 *)(iVar4 + 0x52) = 0;
      bVar1 = *(byte *)(iVar4 + 0x58);
    }
    uVar9 = (uint)_DAT_00012066;
    *(uint *)(iVar4 + 4) = uVar12;
    uVar2 = *(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2);
    *(int *)(iVar4 + 8) = iVar7;
    uVar8 = uVar8 * 2 + uVar9 + (uint)uVar2 * 2;
    if (uVar8 < 0x61a81) {
      *(uint *)(iVar4 + 0x10) = uVar8;
    }
    else {
      *(undefined4 *)(iVar4 + 0x10) = 400000;
    }
    r_lld_sync_insert_eco(uVar6,acStack_41,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

