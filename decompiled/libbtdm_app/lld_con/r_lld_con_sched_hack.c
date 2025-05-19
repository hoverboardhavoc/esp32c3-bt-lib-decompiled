/*
 * Last changed at upstream commit 72599d583c232ea78d6461b5b502426c6e5a1ec9
 * https://github.com/espressif/esp32c3-bt-lib/commit/72599d583c232ea78d6461b5b502426c6e5a1ec9
 * Upstream date: 2025-05-19 16:27:45 +0800
 * Upstream subject: Update bt lib for ESP32-C3 and ESP32-S3(6cfabcd8)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_sched_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_sched_hack(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  short sVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  uVar1 = *(ushort *)(iVar3 + 0x84);
  uVar10 = *(uint *)(iVar3 + 0x48);
  uVar4 = (uint)DAT_00016026 << 1;
  if ((uVar1 & 2) == 0) {
    *(undefined1 *)(iVar3 + 0x16) = 0x1f;
  }
  if (((uVar1 & 3) == 3) && (*(undefined1 *)(iVar3 + 0x96) = 0, param_3 != 0)) {
    uVar2 = *(ushort *)(iVar3 + 0x72);
    if ((uVar2 != 0) &&
       ((((uVar1 & 0x404) == 0x400 && ((uVar1 & 8) == 0)) && (*(char *)(iVar3 + 0x46) == '\0')))) {
      uVar10 = (uint)uVar2 * *(int *)(iVar3 + 100) + uVar10 & 0xfffffff;
      *(ushort *)(iVar3 + 0x7e) = uVar2 + *(short *)(iVar3 + 0x7e);
      *(undefined1 *)(iVar3 + 0x96) = 1;
    }
  }
  for (; (param_2 - uVar10 & 0xfffffff) < 0x7ffffff;
      uVar10 = *(int *)(iVar3 + 100) + uVar10 & 0xfffffff) {
    *(short *)(iVar3 + 0x7e) = *(short *)(iVar3 + 0x7e) + 1;
  }
  uVar12 = *(uint *)(iVar3 + 0x58);
  if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x43) == '\0')) &&
     ((ushort)((*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44)) <
      0x7fff)) {
    if (*(char *)(iVar3 + 0x42) == '\0') {
      uVar10 = *(ushort *)(iVar3 + 0x3c) + uVar10 & 0xfffffff;
      if ((uVar1 & 1) != 0) {
        uVar10 = (*(ushort *)(iVar3 + 0x40) >> 1) + uVar10 & 0xfffffff;
      }
      *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x34);
      *(undefined2 *)(iVar3 + 0x72) = *(undefined2 *)(iVar3 + 0x3e);
      *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar3 + 0x38);
      *(undefined1 *)(iVar3 + 0x42) = 1;
      if (((uVar1 & 1) == 0) ||
         ((**(code **)(_r_ip_funcs_p + 0x36c))
                    (*(undefined1 *)(iVar3 + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c)),
         (*(ushort *)(iVar3 + 0x84) & 1) == 0)) {
        *(undefined1 *)(iVar3 + 0x43) = 1;
      }
    }
    sVar7 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
    uVar12 = uVar10;
    while (sVar7 = sVar7 + -1, sVar7 != -1) {
      uVar12 = uVar12 - *(int *)(iVar3 + 100) & 0xfffffff;
    }
  }
  if ((*(ushort *)(iVar3 + 0x84) & 2) == 0) {
    uVar11 = *(int *)(iVar3 + 100) * 6;
  }
  else {
    uVar11 = *(uint *)(iVar3 + 0x68);
  }
  iVar13 = 0;
  while( true ) {
    if (uVar11 < (uVar10 - uVar12 & 0xfffffff)) {
      uVar5 = 8;
      if ((*(ushort *)(iVar3 + 0x84) & 2) == 0) {
        uVar5 = 0x3e;
      }
                    /* WARNING: Could not recover jumptable at 0x000102f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 800))(param_1,1,uVar5,*(code **)(_r_ip_funcs_p + 800));
      return;
    }
    uVar9 = uVar10;
    if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
      iVar8 = *(int *)(iVar3 + 0x50);
      sVar7 = *(short *)(iVar3 + 0x6e);
      iVar13 = (**(code **)(_r_modules_funcs_p + 0x28c))(*(code **)(_r_modules_funcs_p + 0x28c));
      uVar4 = 0x14;
      if (iVar13 == 0) {
        uVar4 = (uint)*(ushort *)(_p_lld_env + 0xd4);
      }
      uVar1 = *(ushort *)(iVar3 + 0x7a);
      iVar13 = (**(code **)(_r_ip_funcs_p + 0x91c))(*(code **)(_r_ip_funcs_p + 0x91c));
      uVar4 = (((uVar1 + uVar4) * (uVar10 - iVar8 & 0xfffffff)) / 0x640 + 0x40) * 2;
      if (param_3 != 0) {
        *(undefined2 *)(iVar13 + (param_1 + 0x10) * 2 + 8) = 0;
      }
      if ((*(ushort *)(iVar3 + 0x84) & 2) == 0) {
        uVar4 = uVar4 + (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
      }
      else if ((*(ushort *)(iVar3 + 0x7c) < 7) &&
              ((param_3 == 0 ||
               ((*(ushort *)(iVar3 + 0x7c) == 0 && (*(short *)(iVar3 + 0x98) == -1)))))) {
        iVar13 = iVar13 + param_1 * 2;
        uVar1 = *(ushort *)(iVar13 + 0x28);
        uVar4 = uVar4 + ((int)((uint)uVar1 * (uint)*(ushort *)(iVar3 + 0x70) * 0x271) >> 1) +
                        (uint)*(ushort *)(iVar3 + 0x70) * 0x271;
        uVar9 = *(int *)(iVar3 + 100) * 0x271;
        if (uVar9 < uVar4) {
          uVar4 = uVar9;
        }
        *(ushort *)(iVar13 + 0x28) = uVar1 + 1;
      }
      if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x42) != '\0')) &&
         (*(char *)(iVar3 + 0x43) == '\0')) {
        uVar4 = uVar4 + (uint)*(ushort *)(iVar3 + 0x40) * 0x271;
      }
      uVar6 = (uVar4 >> 1) / 0x271;
      uVar9 = uVar10 - uVar6 & 0xfffffff;
      iVar13 = ((int)sVar7 - (uVar4 >> 1)) + uVar6 * 0x271;
      if (iVar13 < 0) {
        uVar9 = uVar9 - 1 & 0xfffffff;
        iVar13 = iVar13 + 0x271;
      }
      *(int *)(iVar3 + 8) = iVar13;
      *(uint *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x5c) + uVar4;
    }
    *(uint *)(iVar3 + 4) = uVar9;
    iVar8 = (**(code **)(_r_ip_funcs_p + 0x6b0))(iVar3,*(code **)(_r_ip_funcs_p + 0x6b0));
    if (iVar8 == 0) break;
    *(char *)(iVar3 + 0x16) = *(char *)(iVar3 + 0x16) + DAT_00016019;
    uVar10 = *(int *)(iVar3 + 100) + uVar10 & 0xfffffff;
    sVar7 = *(short *)(iVar3 + 0x7e);
    *(short *)(iVar3 + 0x7e) = sVar7 + 1;
    if (((*(char *)(iVar3 + 0x46) == '\x01') && (*(char *)(iVar3 + 0x43) == '\0')) &&
       ((ushort)(((sVar7 + 1) - *(short *)(iVar3 + 0x44)) + *(short *)(iVar3 + 0x7c)) < 0x7fff)) {
      if (*(char *)(iVar3 + 0x42) == '\0') {
        uVar10 = *(ushort *)(iVar3 + 0x3c) + uVar10 & 0xfffffff;
        if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
          uVar10 = (*(ushort *)(iVar3 + 0x40) >> 1) + uVar10 & 0xfffffff;
        }
        *(undefined4 *)(iVar3 + 100) = *(undefined4 *)(iVar3 + 0x34);
        *(undefined2 *)(iVar3 + 0x72) = *(undefined2 *)(iVar3 + 0x3e);
        *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar3 + 0x38);
        if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
          (**(code **)(_r_ip_funcs_p + 0x36c))
                    (*(undefined1 *)(iVar3 + 0x8e),*(code **)(_r_ip_funcs_p + 0x36c));
        }
        *(undefined1 *)(iVar3 + 0x42) = 1;
        uVar11 = *(uint *)(iVar3 + 0x68);
        if ((*(ushort *)(iVar3 + 0x84) & 1) == 0) {
          *(undefined1 *)(iVar3 + 0x43) = 1;
        }
      }
      sVar7 = (*(short *)(iVar3 + 0x7c) + *(short *)(iVar3 + 0x7e)) - *(short *)(iVar3 + 0x44);
      uVar12 = uVar10;
      while (sVar7 = sVar7 + -1, sVar7 != -1) {
        uVar12 = uVar12 - *(int *)(iVar3 + 100) & 0xfffffff;
      }
    }
  }
  *(undefined1 *)(iVar3 + 0x8f) = 0;
  *(uint *)(iVar3 + 0x48) = uVar10;
  if ((*(ushort *)(iVar3 + 0x84) & 1) != 0) {
    *(short *)(iVar3 + 0x6c) = (short)iVar13;
    *(uint *)(iVar3 + 0x4c) = (uint)DAT_00016026 * 2 + uVar4;
  }
  return;
}

