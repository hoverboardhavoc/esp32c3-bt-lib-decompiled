/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> lld_sync.o -> r_lld_sync_sched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_sync_sched(int param_1,char param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  uint uVar9;
  char acStack_41 [16];
  char acStack_31 [9];
  
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_31[0] = '\0';
  acStack_41[0] = param_2;
  do {
    bVar1 = DAT_00012055;
    if (acStack_41[0] == '\0') {
      *(undefined1 *)(iVar3 + 0x16) = co_sca2ppm;
    }
    else {
      if (0xff < (uint)*(byte *)(iVar3 + 0x16) + (uint)DAT_00012055) {
        r_assert_err(0,"lld_sync.c",0x329);
      }
      *(byte *)(iVar3 + 0x16) = bVar1 + *(char *)(iVar3 + 0x16);
    }
    if (*(char *)(iVar3 + 99) == '\x01') {
      uVar5 = *(uint *)(iVar3 + 0x2c);
      bVar1 = *(byte *)(iVar3 + 0x31);
      iVar4 = (int)*(short *)(iVar3 + 0x28);
      uVar9 = *(uint *)(iVar3 + 0x24);
    }
    else {
      iVar4 = 1;
      if ((((*(char *)(iVar3 + 100) != '\0') && (*(char *)(iVar3 + 0x62) == '\0')) &&
          (*(short *)(iVar3 + 0x4c) != 0)) && (iVar4 = -1, acStack_41[0] == '\0')) {
        sVar8 = *(short *)(iVar3 + 0x4c) + 1;
        iVar4 = (int)sVar8;
        *(short *)(iVar3 + 0x4e) = sVar8 + *(short *)(iVar3 + 0x4a);
      }
      *(short *)(iVar3 + 0x4a) = *(short *)(iVar3 + 0x4a) + (short)iVar4;
      *(uint *)(iVar3 + 0x44) = iVar4 * *(int *)(iVar3 + 0x40) + *(int *)(iVar3 + 0x44) & 0xfffffff;
      iVar4 = r_lld_read_clock();
      if ((iVar4 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) & 0xfffffff) < 0x8000001) {
        iVar4 = r_lld_read_clock();
        uVar5 = iVar4 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) & 0xfffffff;
        if (uVar5 != 0) {
          uVar2 = *(ushort *)(iVar3 + 0x4a);
          uVar6 = *(uint *)(iVar3 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar3 + 0x4e) & 0xffff) < 0x7fff) {
            iVar4 = ((uVar6 - 1) + uVar5) / uVar6 << 0x10;
          }
          else {
            iVar4 = ((*(ushort *)(iVar3 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar3 + 100) = 0;
          }
          *(ushort *)(iVar3 + 0x4a) = (short)((uint)iVar4 >> 0x10) + uVar2;
          *(uint *)(iVar3 + 0x44) = (iVar4 >> 0x10) * uVar6 + *(int *)(iVar3 + 0x44) & 0xfffffff;
        }
      }
      else {
        r_lld_read_clock();
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        uVar5 = *(int *)(iVar3 + 0x40) * 6;
      }
      else {
        uVar5 = *(uint *)(iVar3 + 0x34);
      }
      if (uVar5 < (*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x3c) & 0xfffffffU)) {
_L211:
        r_lld_sync_cleanup(param_1,8);
        return;
      }
      iVar4 = r_rwip_active_check();
      uVar5 = 0x14;
      if (iVar4 == 0) {
        uVar5 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar4 = (((uint)((*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar3 + 0x5a) * 2) + uVar5)) / 100 + 0x10;
      uVar5 = iVar4 * 2;
      uVar9 = *(int *)(iVar3 + 0x44) - uVar5 / 0x271 & 0xfffffff;
      uVar6 = (uint)*(ushort *)(iVar3 + 0x48) + iVar4 * -2 + (uVar5 / 0x271) * 0x271;
      iVar4 = (int)(short)uVar6;
      if (iVar4 < 0) {
        uVar9 = uVar9 - 1 & 0xfffffff;
        iVar4 = (int)(((uVar6 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        iVar7 = 300;
        if (*(char *)(iVar3 + 0x56) == '\0') {
          iVar7 = 0x1e;
        }
        uVar5 = uVar5 + iVar7;
        if (((uint)(*(int *)(iVar3 + 0x40) * 0x271) >> 1) - 0x96 < uVar5 >> 1) goto _L211;
      }
      *(undefined2 *)(iVar3 + 0x52) = 0;
      bVar1 = *(byte *)(iVar3 + 0x58);
    }
    uVar6 = (uint)_DAT_00012066;
    *(uint *)(iVar3 + 4) = uVar9;
    uVar2 = *(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2);
    *(int *)(iVar3 + 8) = iVar4;
    uVar5 = uVar5 * 2 + uVar6 + (uint)uVar2 * 2;
    if (uVar5 < 0x61a81) {
      *(uint *)(iVar3 + 0x10) = uVar5;
    }
    else {
      *(undefined4 *)(iVar3 + 0x10) = 400000;
    }
    r_lld_sync_insert_eco(param_1,acStack_41,acStack_31);
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

