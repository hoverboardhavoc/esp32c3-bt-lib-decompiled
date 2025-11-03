/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app -> lld_sync.o -> r_lld_sync_sched
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
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  char cVar9;
  char acStack_41 [16];
  char acStack_31 [5];
  
  iVar3 = *(int *)(&lld_sync_env + param_1 * 4);
  acStack_31[0] = '\0';
  acStack_41[0] = param_2;
  do {
    bVar1 = DAT_0001302d;
    cVar9 = co_sca2ppm;
    if (acStack_41[0] != '\0') {
      if (0xff < (uint)*(byte *)(iVar3 + 0x16) + (uint)DAT_0001302d) {
        (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x342,*(code **)(_r_plf_funcs_p + 8));
      }
      cVar9 = bVar1 + *(char *)(iVar3 + 0x16);
    }
    *(char *)(iVar3 + 0x16) = cVar9;
    if (*(char *)(iVar3 + 99) == '\x01') {
      uVar4 = *(uint *)(iVar3 + 0x2c);
      bVar1 = *(byte *)(iVar3 + 0x31);
      iVar6 = (int)*(short *)(iVar3 + 0x28);
      uVar5 = *(uint *)(iVar3 + 0x24);
    }
    else {
      iVar6 = 1;
      if ((((*(char *)(iVar3 + 100) != '\0') && (*(char *)(iVar3 + 0x62) == '\0')) &&
          (*(ushort *)(iVar3 + 0x4c) != 0)) && (iVar6 = -1, acStack_41[0] == '\0')) {
        iVar7 = *(ushort *)(iVar3 + 0x4c) + 1;
        iVar6 = iVar7 * 0x10000 >> 0x10;
        *(short *)(iVar3 + 0x4e) = (short)iVar7 + *(short *)(iVar3 + 0x4a);
      }
      *(short *)(iVar3 + 0x4a) = *(short *)(iVar3 + 0x4a) + (short)iVar6;
      *(uint *)(iVar3 + 0x44) = iVar6 * *(int *)(iVar3 + 0x40) + *(int *)(iVar3 + 0x44) & 0xfffffff;
      iVar6 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      if ((((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) + iVar6 & 0xfffffff) < 0x8000001) {
        iVar6 = (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
        uVar4 = iVar6 + ((uint)rwip_prog_delay * 2 - *(int *)(iVar3 + 0x44)) & 0xfffffff;
        if (uVar4 != 0) {
          uVar2 = *(ushort *)(iVar3 + 0x4a);
          uVar5 = *(uint *)(iVar3 + 0x40);
          if (((uint)uVar2 - (uint)*(ushort *)(iVar3 + 0x4e) & 0xffff) < 0x7fff) {
            iVar6 = ((uVar5 - 1) + uVar4) / uVar5 << 0x10;
          }
          else {
            iVar6 = ((*(ushort *)(iVar3 + 0x4e) + 1) - (uint)uVar2) * 0x10000;
            *(undefined1 *)(iVar3 + 100) = 0;
          }
          *(ushort *)(iVar3 + 0x4a) = uVar2 + (short)((uint)iVar6 >> 0x10);
          *(uint *)(iVar3 + 0x44) = (iVar6 >> 0x10) * uVar5 + *(int *)(iVar3 + 0x44) & 0xfffffff;
        }
      }
      else {
        (**(code **)(_r_ip_funcs_p + 0x264))(*(code **)(_r_ip_funcs_p + 0x264));
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        uVar4 = *(int *)(iVar3 + 0x40) * 6;
      }
      else {
        uVar4 = *(uint *)(iVar3 + 0x34);
      }
      if (uVar4 < (*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x3c) & 0xfffffffU)) {
_L205:
        (**(code **)(_r_ip_funcs_p + 0x13c))(param_1,8,*(code **)(_r_ip_funcs_p + 0x13c));
        return;
      }
      iVar6 = (**(code **)(_r_modules_funcs_p + 0x28c))(*(code **)(_r_modules_funcs_p + 0x28c));
      uVar4 = 0x14;
      if (iVar6 == 0) {
        uVar4 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      iVar6 = (((uint)((*(int *)(iVar3 + 0x44) - *(int *)(iVar3 + 0x38)) * 0x10) >> 8) *
              (*(ushort *)(&co_sca2ppm + (uint)*(byte *)(iVar3 + 0x5a) * 2) + uVar4)) / 100 + 0x10;
      uVar4 = iVar6 * 2;
      uVar5 = *(int *)(iVar3 + 0x44) - uVar4 / 0x271 & 0xfffffff;
      uVar8 = (uint)*(ushort *)(iVar3 + 0x48) + iVar6 * -2 + (uVar4 / 0x271) * 0x271;
      iVar6 = (int)(uVar8 * 0x10000) >> 0x10;
      if (iVar6 < 0) {
        uVar5 = uVar5 - 1 & 0xfffffff;
        iVar6 = (int)(((uVar8 & 0xffff) + 0x271) * 0x10000) >> 0x10;
      }
      if (*(char *)(iVar3 + 0x57) == '\0') {
        iVar7 = 300;
        if (*(char *)(iVar3 + 0x56) == '\0') {
          iVar7 = 0x1e;
        }
        uVar4 = uVar4 + iVar7;
        if (((uint)(*(int *)(iVar3 + 0x40) * 0x271) >> 1) - 0x96 < uVar4 >> 1) goto _L205;
      }
      bVar1 = *(byte *)(iVar3 + 0x58);
      *(undefined2 *)(iVar3 + 0x52) = 0;
    }
    *(uint *)(iVar3 + 4) = uVar5;
    uVar5 = (uint)_DAT_0001304e;
    *(int *)(iVar3 + 8) = iVar6;
    uVar4 = uVar4 * 2 + uVar5 + (uint)*(ushort *)(&lld_sync_max_aux_dur_tab + (uint)bVar1 * 2) * 2;
    if (400000 < uVar4) {
      uVar4 = 400000;
    }
    *(uint *)(iVar3 + 0x10) = uVar4;
    (**(code **)(_r_ip_funcs_p + 0x7a4))
              (param_1,acStack_41,acStack_31,*(code **)(_r_ip_funcs_p + 0x7a4));
    if (acStack_31[0] != '\0') {
      return;
    }
  } while( true );
}

